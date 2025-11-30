#include <iostream>
using namespace std;

class Node {
public:
    string data;
    int priority;
    Node* next;

    Node(string d, int p) {
        data = d;
        priority = p;
        next = NULL;
    }
};

class PriorityQueue {
    Node* head;

public:
    PriorityQueue() {
        head = NULL;
    }

    void enqueue(string data, int priority) {
        Node* newNode = new Node(data, priority);

        // Insert at start if queue empty or higher priority
        if (head == NULL || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } 
        else {
            Node* temp = head;
            while (temp->next != NULL && temp->next->priority <= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "Inserted: " << data << " (Priority: " << priority << ")" << endl;
    }

    void dequeue() {
        if (head == NULL) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }

        cout << "Removed: " << head->data << " (Priority: " << head->priority << ")" << endl;
        head = head->next;
    }

    void display() {
        if (head == NULL) {
            cout << "Queue Empty" << endl;
            return;
        }

        cout << "Priority Queue: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << "[" << temp->data << ", P:" << temp->priority << "] -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue("Email", 3);
    pq.enqueue("Manager Approval", 1);
    pq.enqueue("Team Lead Review", 2);

    pq.display();

    pq.dequeue();
    pq.display();

    return 0;
}

