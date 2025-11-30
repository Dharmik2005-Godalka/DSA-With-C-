#include <iostream>
using namespace std;

class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node(string u) {
        url = u;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
    Node* current;

public:
    BrowserHistory(string home) {
        current = new Node(home);
        cout << "Home Page: " << home << endl;
    }

    void visit(string url) {
        Node* newPage = new Node(url);
        current->next = newPage;
        newPage->prev = current;
        current = newPage;
        cout << "Visited: " << url << endl;
    }

    void back() {
        if (current->prev) {
            current = current->prev;
            cout << "Back to: " << current->url << endl;
        }
    }

    void forward() {
        if (current->next) {
            current = current->next;
            cout << "Forward to: " << current->url << endl;
        }
    }
};

int main() {
    BrowserHistory b("google.com");

    b.visit("youtube.com");
    b.visit("github.com");
    b.back();
    b.forward();
    b.visit("codeforces.com");

    return 0;
}

