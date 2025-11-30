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

    int length() {
        if (!head) return 0;

        int count = 0;
        CNode* temp = head;

        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }

    bool detectLoop() {
        if (!head || !head->next) return false;

        CNode *slow = head, *fast = head;

        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main() {
    CircularList cl;
    cl.insert(10);
    cl.insert(20);
    cl.insert(30);

    cout << "Length: " << cl.length() << endl;

    if (cl.detectLoop())
        cout << "Loop detected" << endl;
    else
        cout << "No loop" << endl;

    return 0;
}

