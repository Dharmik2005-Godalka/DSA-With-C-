#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void splitList(struct Node *head, struct Node **oddList, struct Node **evenList) {
    while (head != NULL) {
        if (head->data % 2 == 0)
            insert(evenList, head->data);
        else
            insert(oddList, head->data);

        head = head->next;
    }
}

int main() {
    struct Node *head = NULL, *odd = NULL, *even = NULL;

    insert(&head, 17);
    insert(&head, 50);
    insert(&head, 23);
    insert(&head, 68);
    insert(&head, 35);

    printf("\nOriginal Linked List:\n");
    display(head);

    splitList(head, &odd, &even);

    printf("\nOdd Linked List:\n");
    display(odd);

    printf("\nEven Linked List:\n");
    display(even);

    return 0;
}

