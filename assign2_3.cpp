#include <iostream>
#include <string>
#include <vector>
#include <simplecpp>
using namespace std;

struct Book{
    int id;
    string title;
    string author;
    float price;
};

void input(Book &book){
    cout << "Enter the id of the book: ";
    cin >> book.id;
    cout << "Enter the title of the book: ";
    cin.ignore();
    getline(cin, book.title);
    cout << "Enter the author of the book: ";
    getline(cin, book.author);
    cout << "Enter the price of the book: ";
    cin >> book.price;
}

void output(Book book){
    cout << "The id of the book is: " << book.id << endl;
    cout << "The title of the book is: " << book.title << endl;
    cout << "The author of the book is: " << book.author << endl;
    cout << "The price of the book is: " << book.price << endl;
}

int main(){
    vector<Book> books;
    int choice;
    string searchTitle;
    
    do {
        cout << "1. Add a book" << endl;
        cout << "2. Search for a book by title" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        Book newBook; // Declare the variable outside the switch statement
        switch (choice) {
            case 1:
                input(newBook);
                books.push_back(newBook);
                break;
            case 2:
                cout << "Enter the title to search for: ";
                cin.ignore();
                getline(cin, searchTitle);
                for (const auto& book : books) {
                    if (book.title == searchTitle) {
                        output(book);
                        break;
                    }
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 3);
    
    return 0;
}
