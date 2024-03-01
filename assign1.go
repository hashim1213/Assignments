package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Token types
const (
	TokenInt   = "INT"
	TokenPlus  = "+"
	TokenMinus = "-"
	TokenMul   = "*"
	TokenEOF   = "EOF"
)

// Token represents a lexical token.
type Token struct {
	Type  string // Type of the token
	Value string // Value of the token (for integers)
}

// Scanner splits the input into tokens
func Scanner(input string) []Token {
	var tokens []Token
	fields := strings.Fields(input)

	for _, field := range fields {
		switch field {
		case "+":
			tokens = append(tokens, Token{Type: TokenPlus})
		case "*":
			tokens = append(tokens, Token{Type: TokenMul})
		case "-":
			tokens = append(tokens, Token{Type: TokenMinus})
		default:
			if _, err := strconv.Atoi(field); err == nil {
				tokens = append(tokens, Token{Type: TokenInt, Value: field})
			} else {
				// Invalid token
				tokens = append(tokens, Token{Type: "INVALID"})
			}
		}
	}
	tokens = append(tokens, Token{Type: TokenEOF})
	return tokens
}

// Parser checks if the token list is valid according to the grammar
type Parser struct {
	tokens []Token
	pos    int
}

func NewParser(tokens []Token) *Parser {
	return &Parser{tokens: tokens, pos: 0}
}

func (p *Parser) accept(tokenType string) bool {
	if p.pos < len(p.tokens) && p.tokens[p.pos].Type == tokenType {
		p.pos++
		return true
	}
	return false
}

func (p *Parser) expect(tokenType string) bool {
	if p.accept(tokenType) {
		return true
	}
	if p.pos < len(p.tokens) {
		fmt.Printf("Unexpected token: %v, expected: %v\n", p.tokens[p.pos], tokenType)
	}
	return false
}

func (p *Parser) parseNumber() bool {
	return p.accept(TokenInt) || (p.accept(TokenMinus) && p.accept(TokenInt))
}

func (p *Parser) parseTerm() bool {
	if !p.parseNumber() {
		return false
	}
	for p.accept(TokenMul) {
		if !p.parseNumber() {
			return false
		}
	}
	return true
}

func (p *Parser) parseExp() bool {
	if !p.parseTerm() {
		return false
	}
	for p.accept(TokenPlus) {
		if !p.parseExp() {
			return false
		}
	}
	return true
}

func (p *Parser) Validate() bool {
	return p.parseExp() && p.accept(TokenEOF)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		input := scanner.Text()
		tokens := Scanner(input)
		parser := NewParser(tokens)

		if len(tokens) == 1 && tokens[0].Type == "INVALID" {
			fmt.Printf("\"%s\" contains lexical units which are not lexemes (valid)\n", input)
		} else if !parser.Validate() {
			fmt.Printf("\"%s\" is not an expression\n", input)
		} else {
			fmt.Printf("\"%s\" is an expression\n", input)
		}
	}

	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
}
