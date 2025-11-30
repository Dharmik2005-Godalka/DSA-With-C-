#include <iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack." << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    int size() {
        return top + 1;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.peek() << endl;
    cout << "Stack size: " << st.size() << endl;

    cout << "Popped: " << st.pop() << endl;
    cout << "Top after pop: " << st.peek() << endl;

    return 0;
}

