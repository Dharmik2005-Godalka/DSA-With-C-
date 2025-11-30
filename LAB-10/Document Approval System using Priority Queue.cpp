#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    int priority;
    Node* next;

    Node(string d, int p) {
        data = d;
        priority = p;
        next = nullptr;
    }
};

class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue() {
        head = nullptr;
    }

    void enqueue(string data, int priority) {
        Node* newNode = new Node(data, priority);

        // If queue empty OR new node has higher priority (smaller number)
        if (!head || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->priority <= priority)
                temp = temp->next;

            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "Inserted: " << data << " (Priority: " << priority << ")" << endl;
    }

    void dequeue() {
        if (!head) {
            cout << "Priority Queue is Empty!" << endl;
            return;
        }
        cout << "Removed: " << head->data << " (Priority: " << head->priority << ")" << endl;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        if (!head) {
            cout << "Queue Empty!" << endl;
            return;
        }

        cout << "Priority Queue: ";
        Node* temp = head;
        while (temp) {
            cout << "[" << temp->data << ", P:" << temp->priority << "] -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue("Intern Report", 5);
    pq.enqueue("CEO Signature", 1);
    pq.enqueue("HR Approval", 3);
    pq.enqueue("Manager Report", 2);

    pq.display();
    pq.dequeue();
    pq.display();

    return 0;
}

