#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void countOddEven(struct Node *head) {
    int odd = 0, even = 0;

    while (head != NULL) {
        if (head->data % 2 == 0)
            even++;
        else
            odd++;
        head = head->next;
    }

    printf("\nOdd Count : %d", odd);
    printf("\nEven Count: %d\n", even);
}

void insert(struct Node **head, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

int main() {
    struct Node *head = NULL;

    insert(&head, 45);
    insert(&head, 22);
    insert(&head, 11);
    insert(&head, 66);

    countOddEven(head);

    return 0;
}

