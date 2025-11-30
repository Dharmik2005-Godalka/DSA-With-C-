#include <iostream>
using namespace std;

class Deque {
private:
    int size;
    int *deque;
    int front, rear;

public:
    Deque(int s) {
        size = s;
        deque = new int[size];
        front = rear = -1;
    }

    void insertFront(int value) {
        if ((front == 0 && rear == size-1) || (front == rear+1)) {
            cout << "Deque Full!" << endl;
            return;
        }
        if (front == -1)
            front = rear = 0;
        else if (front == 0)
            front = size - 1;
        else
            front--;

        deque[front] = value;
        cout << "Inserted " << value << " at Front\n";
    }

    void display() {
        if (front == -1) {
            cout << "Deque Empty!" << endl;
            return;
        }
        cout << "Deque: ";
        int i = front;
        while (true) {
            cout << deque[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    Deque d(5);
    d.insertFront(10);
    d.insertFront(20);
    d.display();
}

