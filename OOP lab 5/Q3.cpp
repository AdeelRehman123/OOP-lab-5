#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;

public:
    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }

    void displayInfo() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << endl;
    }
};

class Catalog {
private:
    Book* books[100];
    int bookCount;

public:
    Catalog() : bookCount(0) {
        cout << "Catalog constructed" << endl;
    }

    ~Catalog() {
        cout << "Catalog destroyed" << endl;
    }

    void addBookToCatalog(Book* book) {
        if (bookCount < 100) {
            books[bookCount++] = book;
            cout << "Book added to catalog: " << book->getTitle() << endl;
        } else {
            cout << "no more space in catalog." << endl;
        }
    }

    void findBookInCatalog(const string& isbn) const {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getISBN() == isbn) {
                cout << "Book found in catalog: " << books[i]->getTitle() << endl;
                return;
            }
        }
        cout << "Book not found in catalog." << endl;
    }
};

class Library {
private:
    string name;
    string address;
    Catalog catalog;
    Book* books[100];
    int bookCount;

public:
    Library(string n, string addr) : name(n), address(addr), bookCount(0) {
        cout << "Library constructed: " << name << " at " << address << endl;
    }

    ~Library() {
        cout << "Library destroyed: " << name << endl;
    }

    void addBook(Book* book) {
        if (bookCount < 100) {
            books[bookCount++] = book;
            catalog.addBookToCatalog(book);
        } else {
            cout << "Library is full!" << endl;
        }
    }

    void findBook(const string& isbn) const {
        catalog.findBookInCatalog(isbn);
    }

    void listBooks() const {
        cout << "Books in library: " << name << endl;
        for (int i = 0; i < bookCount; i++) {
            books[i]->displayInfo();
        }
    }
};

int main() {
    cout << "--- Library System Demo ---" << endl;

    Library myLibrary("UniLibrary", "main road");

    Book book1("The Great Gatsby", "F. Scott Fitzgerald", "12345");
    Book book2("1984", "George Orwell", "67890");

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);

    myLibrary.listBooks();
    
    myLibrary.findBook("12345");
    myLibrary.findBook("11111");

    return 0;
}
