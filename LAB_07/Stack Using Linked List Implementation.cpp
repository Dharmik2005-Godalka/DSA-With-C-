#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) { data = val; next = NULL; }
};

class StackLL {
private:
    Node* top;

public:
    StackLL() { top = NULL; }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed." << endl;
    }

    int pop() {
        if (!top) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    int peek() {
        return top ? top->data : -1;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    StackLL s;
    s.push(5);
    s.push(15);
    cout << "Top: " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;

    return 0;
}

