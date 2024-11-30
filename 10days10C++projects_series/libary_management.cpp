#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        Book newBook(id, title, author);
        books.push_back(newBook);
        cout << "Book added successfully!" << endl;
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books in the library." << endl;
            return;
        }
        for (const auto& book : books) {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << endl;
        }
    }

    void searchBookByTitle(string title) {
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "Book found: ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }
};

int main() {
    Library library;
    int choice, id;
    string title, author;

    while (true) {
        cout << "1. Add Book\n2. Display Books\n3. Search Book by Title\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book ID: ";
                cin >> id;
                cin.ignore(); // Ignore newline character
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                library.addBook(id, title, author);
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                cout << "Enter book title: ";
                cin.ignore(); // Ignore newline character
                getline(cin, title);
                library.searchBookByTitle(title);
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
