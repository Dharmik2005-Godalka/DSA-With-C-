#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;

void traverse() {
    if(head == NULL) {
        cout << "List is Empty!\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertAtPosition(int value, int pos) {
    if(pos == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;
    for(int i=1; i<pos-1 && temp!=NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        cout << "Invalid Position!\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// ----------- Searching -----------
void searchElement(int key) {
    Node* temp = head;
    int pos = 1;
    while(temp != NULL) {
        if(temp->data == key) {
            cout << "Element found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element not found!\n";
}

void deleteNode(int pos) {
    if(head == NULL) {
        cout << "List is Empty!\n";
        return;
    }

    Node* temp = head;

    if(pos == 1) {
        head = temp->next;
        delete temp;
        return;
    }

    for(int i=1; temp!=NULL && i<pos-1; i++)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL) {
        cout << "Invalid Position!\n";
        return;
    }

    Node* nextNode = temp->next->next;
    delete temp->next;
    temp->next = nextNode;
}

int main() {
    int choice, value, pos;

    while(true) {
        cout << "\n===== LINKED LIST MENU =====";
        cout << "\n1. Traverse";
        cout << "\n2. Insert at Beginning";
        cout << "\n3. Insert at End";
        cout << "\n4. Insert at Position";
        cout << "\n5. Search Element";
        cout << "\n6. Delete Element";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: traverse(); break;
            case 2: cout << "Enter value: "; cin >> value; insertAtBeginning(value); break;
            case 3: cout << "Enter value: "; cin >> value; insertAtEnd(value); break;
            case 4: cout << "Enter value and position: "; cin >> value >> pos; insertAtPosition(value, pos); break;
            case 5: cout << "Enter element to search: "; cin >> value; searchElement(value); break;
            case 6: cout << "Enter position to delete: "; cin >> pos; deleteNode(pos); break;
            case 7: exit(0);
            default: cout << "Invalid Choice!\n";
        }
    }
    return 0;
}

