#include <iostream>
using namespace std;

class User {
public:
    int userID;
    string name;

    virtual void action() {
        cout << "User performing action\n";
    }
};

class Member : public User {
public:
    void action() {
        cout << "Member borrowing book\n";
    }
};

class Librarian : public User {
public:
    void action() {
        cout << "Librarian managing books\n";
    }
};

int main() {
    User *u;

    Member m;
    Librarian l;

    u = &m;
    u->action();

    u = &l;
    u->action();

    return 0;
}

