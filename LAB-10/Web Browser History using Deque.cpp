#include <iostream>
#include <deque>
#include <string>
using namespace std;

class BrowserHistory {
private:
    deque<string> history;

public:
    void visit(string page) {
        history.push_back(page);
        cout << "Visited: " << page << endl;
    }

    void back() {
        if (history.size() > 1) {
            string last = history.back();
            history.pop_back();
            cout << "Back to: " << history.back() 
                 << " (Removed: " << last << ")" << endl;
        } else {
            cout << "No more history available!" << endl;
        }
    }

    void display() {
        cout << "History: ";
        for (auto page : history)
            cout << page << " ";
        cout << endl;
    }
};

int main() {
    BrowserHistory bh;

    bh.visit("Google");
    bh.visit("YouTube");
    bh.visit("ChatGPT");
    
    bh.display();
    bh.back();
    bh.display();

    return 0;
}

