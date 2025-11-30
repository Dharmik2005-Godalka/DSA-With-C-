#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string status;

public:
    string title, author, ISBN;

    Book(string t, string a, string i) {
        title = t;
        author = a;
        ISBN = i;
        status = "available";
    }

    string getStatus() {
        return status;
    }

    void setStatus(string s) {
        status = s;
    }
};

class Member {
public:
    int memberID;
    string name;
    vector<string> borrowedBooks;

    void addBook(string isbn) {
        borrowedBooks.push_back(isbn);
    }

    void removeBook(string isbn) {
        for(int i=0; i<borrowedBooks.size(); i++) {
            if(borrowedBooks[i] == isbn) {
                borrowedBooks.erase(borrowedBooks.begin() + i);
                break;
            }
        }
    }
};

class Library {
public:
    vector<Book> books;
    vector<Member> members;

    void addBookToLibrary(Book b) {
        books.push_back(b);
    }

    void registerMember(Member m) {
        members.push_back(m);
    }
};

int main() {
    cout << "Task 2: Member Functions Added Successfully!\n";
    return 0;
}

