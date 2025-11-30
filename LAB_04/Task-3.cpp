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

void removeDuplicates(struct Node *head) {
    if (!head) return;

    struct Node *current = head;

    while (current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    insert(&head, 50);
    insert(&head, 50);
    insert(&head, 40);
    insert(&head, 40);
    insert(&head, 20);
    insert(&head, 10);

    printf("\nOriginal Sorted List with Duplicates:\n");
    display(head);

    removeDuplicates(head);

    printf("\nAfter Removing Duplicates:\n");
    display(head);

    return 0;
}

