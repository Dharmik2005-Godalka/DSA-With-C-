#include <iostream>
using namespace std;

class CNode {
public:
    int data;
    CNode* next;

    CNode(int value) {
        data = value;
        next = NULL;
    }
};

class CircularList {
public:
    CNode* head;

    CircularList() {
        head = NULL;
    }

    void insert(int value) {
        CNode* newNode = new CNode(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
};

void roundRobin(CircularList& clist, int timeSlice) {
    if (!clist.head) return;
    CNode* temp = clist.head;

    cout << "\nRound Robin Execution:\n";
    do {
        cout << "Process " << temp->data 
             << " executed for " << timeSlice << " units.\n";
        temp = temp->next;
    } while (temp != clist.head);
}

int main() {
    CircularList cl;
    cl.insert(1);
    cl.insert(2);
    cl.insert(3);
    cl.insert(4);

    roundRobin(cl, 5);
}

