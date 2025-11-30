#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    string title, author, ISBN;
    string status; 
};

class Member {
public:
    int memberID;
    string name;
    vector<string> borrowedBooks;
};

class Library {
public:
    vector<Book> books;
    vector<Member> members;
};

int main() {
    cout << "Task 1: Classes Created Successfully!\n";
    return 0;
}

