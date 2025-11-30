#include <iostream>
#include <vector>
using namespace std;

class BookNotFoundException{};
class MemberNotFoundException{};
class BookNotAvailableException{};

class Book {
private: string status;
public:
    string title, author, ISBN;

    Book(string t,string a,string i):title(t),author(a),ISBN(i),status("available"){}

    string getStatus(){ return status; }
    void setStatus(string s){ status=s; }
};

class Member {
public:
    int memberID;
    string name;
    vector<string> borrowedBooks;

    void borrow(string isbn){ borrowedBooks.push_back(isbn); }
    void removeBorrowed(string isbn){
        for(int i=0;i<borrowedBooks.size();i++)
            if(borrowedBooks[i]==isbn) borrowedBooks.erase(borrowedBooks.begin()+i);
    }
};

class Library {
public:
    vector<Book> books;
    vector<Member> members;

    Book* findBook(string isbn){
        for(auto &b:books) if(b.ISBN==isbn) return &b;
        throw BookNotFoundException();
    }

    Member* findMember(int id){
        for(auto &m:members) if(m.memberID==id) return &m;
        throw MemberNotFoundException();
    }

    void issueBook(int id,string isbn){
        Book *b=findBook(isbn);
        Member *m=findMember(id);

        if(b->getStatus()=="issued") throw BookNotAvailableException();

        b->setStatus("issued");
        m->borrow(isbn);
        cout<<"Book issued!\n";
    }
};

int main(){
    Library lib;
    lib.books.push_back(Book("C++","Stroustrup","101"));
    
    Member m; m.memberID=1; m.name="Dharmik";
    lib.members.push_back(m);

    try{
        lib.issueBook(1,"101");
        lib.issueBook(1,"101");
    }
    catch(BookNotFoundException){ cout<<"Book not found!\n"; }
    catch(MemberNotFoundException){ cout<<"Member not found!\n"; }
    catch(BookNotAvailableException){ cout<<"Book already issued!\n"; }

    return 0;
}

