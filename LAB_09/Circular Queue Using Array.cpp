#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    void enqueue(int value) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue Full!\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << value << " inserted.\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Empty!\n";
            return;
        }
        cout << arr[front] << " removed.\n";
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    void display() {
        if (front == -1) {
            cout << "Queue Empty.\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main(){
    CircularQueue q;
    q.enqueue(11);
    q.enqueue(22);
    q.enqueue(33);
    q.dequeue();
    q.display();
    return 0;
}

