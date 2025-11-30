#include <iostream>
using namespace std;

#define SIZE 5

class LinearQueue {
    int arr[SIZE];
    int front, rear;

public:
    LinearQueue() {
        front = rear = -1;
    }

    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << value << " inserted.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << arr[front++] << " removed.\n";
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty.\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    LinearQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.display();
    return 0;
}

