#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class CircularQueue {
    Node* front;
    Node* rear;

public:
    CircularQueue(){
        front = rear = NULL;
    }

    void enqueue(int value){
        Node* newNode = new Node(value);

        if (!front){
            front = rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
        cout << value << " inserted.\n";
    }

    void dequeue(){
        if (!front){
            cout << "Queue Empty!\n";
            return;
        }
        if (front == rear){
            cout << front->data << " removed.\n";
            front = rear = NULL;
        } else {
            cout << front->data << " removed.\n";
            front = front->next;
            rear->next = front;
        }
    }

    void display(){
        if (!front){
            cout << "Queue Empty.\n";
            return;
        }
        cout << "Queue: ";
        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main(){
    CircularQueue q;
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);
    q.dequeue();
    q.display();
    return 0;
}

