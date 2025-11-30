#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string status;

public:
    string title, author, ISBN;

    Book(string t, string a, string i) {
        title = t; author = a; ISBN = i;
        status = "available";
    }

    string getStatus() { return status; }
    void setStatus(string s) { status = s; }
};

class Member {
public:
    int memberID;
    string name;
    vector<string> borrowedBooks;

    void addBorrowedBook(string isbn) {
        borrowedBooks.push_back(isbn);
    }

    void returnBorrowedBook(string isbn) {
        for(int i=0; i<borrowedBooks.size(); i++) {
            if(borrowedBooks[i] == isbn) {
                borrowedBooks.erase(borrowedBooks.begin()+i);
                break;
            }
        }
    }
};

class Library {
public:
    vector<Book> books;
    vector<Member> members;

    Book* findBook(string isbn) {
        for(int i=0; i<books.size(); i++)
            if(books[i].ISBN == isbn) return &books[i];
        return NULL;
    }

    Member* findMember(int id) {
        for(int i=0; i<members.size(); i++)
            if(members[i].memberID == id) return &members[i];
        return NULL;
    }

    void issueBook(int memberID, string isbn) {
        Book* b = findBook(isbn);
        Member* m = findMember(memberID);

        if(b && m && b->getStatus()=="available") {
            b->setStatus("issued");
            m->addBorrowedBook(isbn);
            cout << "Book Issued Successfully!\n";
        }
    }

    void returnBook(int memberID, string isbn) {
        Book* b = findBook(isbn);
        Member* m = findMember(memberID);

        if(b && m) {
            b->setStatus("available");
            m->returnBorrowedBook(isbn);
            cout << "Book Returned Successfully!\n";
        }
    }
};

int main() {
    cout << "Task 3: Book Issue/Return Feature Added!\n";
    return 0;
}

