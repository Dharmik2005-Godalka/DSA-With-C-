#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head = NULL;

    int countNodes() {
        int count = 0;
        Node* temp = head;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {

    LinkedList list;
    Node* n1 = new Node{10, NULL};
    Node* n2 = new Node{20, NULL};
    Node* n3 = new Node{30, NULL};

    n1->next = n2;
    n2->next = n3;
    list.head = n1;

    cout << "Total nodes: " << list.countNodes();

    return 0;
}

