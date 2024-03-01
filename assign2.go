package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Token represents a lexical token.
type Token struct {
	Type    TokenType
	Literal string
}

// TokenType is a type for defining different types of tokens.
type TokenType string

const (
	// Special tokens
	ILLEGAL TokenType = "ILLEGAL"
	EOF     TokenType = "EOF"

	// Literals
	INT   TokenType = "INT"   // 0, 1, 2, ...
	PLUS  TokenType = "PLUS"  // +
	MINUS TokenType = "MINUS" // -
	STAR  TokenType = "STAR"  // *

	// Misc
	WHITESPACE TokenType = "WHITESPACE"
)

// scanner scans the input string and produces tokens.
func scanner(input string) []Token {
	var tokens []Token
	// Using strings.Fields to eliminate whitespaces and split the input into parts
	parts := strings.Fields(input)
	for _, part := range parts {
		switch part {
		case "+":
			tokens = append(tokens, Token{PLUS, part})
		case "-":
			tokens = append(tokens, Token{MINUS, part})
		case "*":
			tokens = append(tokens, Token{STAR, part})
		default:
			if _, err := strconv.Atoi(part); err == nil {
				tokens = append(tokens, Token{INT, part})
			} else {
				tokens = append(tokens, Token{ILLEGAL, part})
			}
		}
	}
	return tokens
}

// parser functions
func parseExp(tokens []Token, pos *int) bool {
	if parseTerm(tokens, pos) {
		if *pos < len(tokens) && tokens[*pos].Type == PLUS {
			*pos++
			return parseExp(tokens, pos)
		}
		return true
	}
	return false
}

func parseTerm(tokens []Token, pos *int) bool {
	if parseNumber(tokens, pos) {
		if *pos < len(tokens) && tokens[*pos].Type == STAR {
			*pos++
			return parseTerm(tokens, pos)
		}
		return true
	}
	return false
}

func parseNumber(tokens []Token, pos *int) bool {
	if *pos < len(tokens) {
		token := tokens[*pos]
		if token.Type == INT || token.Type == MINUS {
			if token.Type == MINUS {
				*pos++
				if *pos < len(tokens) && tokens[*pos].Type == INT {
					*pos++
					return true
				}
				return false
			}
			*pos++
			return true
		}
	}
	return false
}

// evaluateInput evaluates the input string and prints the result.
func evaluateInput(input string) {
	tokens := scanner(input)
	pos := 0
	if len(tokens) == 0 || tokens[len(tokens)-1].Type == ILLEGAL {
		fmt.Printf("\"%s\" contains lexical units which are not lexemes (valid)\n", input)
	} else if parseExp(tokens, &pos) && pos == len(tokens) {
		fmt.Printf("\"%s\" is an expression\n", input)
	} else {
		fmt.Printf("\"%s\" is not an expression\n", input)
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		evaluateInput(line)
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
}
