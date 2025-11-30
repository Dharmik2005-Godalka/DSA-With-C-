#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }
    
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int value) {
        Node* temp = head;
        while (temp != NULL && temp->data != value)
            temp = temp->next;

        if (!temp) return; // not found

        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;

        if (temp->next) temp->next->prev = temp->prev;

        delete temp;
    }

    bool search(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insert(10);
    dll.insert(20);
    dll.insert(30);

    cout << "Doubly Linked List: ";
    dll.display();

    cout << "Deleting 20...\n";
    dll.deleteNode(20);
    dll.display();

    cout << "Searching 30: " << (dll.search(30) ? "Found" : "Not Found") << endl;

    return 0;
}

