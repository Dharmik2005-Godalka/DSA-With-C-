#include <iostream>
using namespace std;

class CNode {
public:
    int data;
    CNode* next;

    CNode(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    CNode* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        CNode* newNode = new CNode(value);
        if (!head) {
            head = newNode;
            return;
        }
        CNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        CNode* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void createLoop(int pos) {
        if (!head) return;

        CNode* temp = head;
        CNode* loopNode = nullptr;
        int count = 1;

        while (temp->next) {
            if (count == pos)
                loopNode = temp;
            temp = temp->next;
            count++;
        }
        temp->next = loopNode;
    }

    bool detectLoop() {
        CNode* slow = head;
        CNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    void removeLoop() {
        if (!head || !head->next) return;

        CNode* slow = head;
        CNode* fast = head;

        do {
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = nullptr;
    }
};

int main() {
    LinkedList ll;

    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(40);
    ll.insert(50);

    ll.createLoop(3);

    if (ll.detectLoop())
        cout << "Loop detected\n";
    else
        cout << "No loop\n";

    ll.removeLoop();

    if (ll.detectLoop())
        cout << "Loop still exists\n";
    else
        cout << "Loop removed successfully\n";

    ll.display();

    return 0;
}

