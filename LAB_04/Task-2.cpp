#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert(struct Node **head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

int findKthSmallest(struct Node *head, int k) {
    int count = 1;
    while (head != NULL) {
        if (count == k)
            return head->data;
        head = head->next;
        count++;
    }
    return -1;
}

int main() {
    struct Node *head = NULL;
    int k = 3;

    insert(&head, 50);
    insert(&head, 40);
    insert(&head, 30);
    insert(&head, 20);
    insert(&head, 10);

    int result = findKthSmallest(head, k);

    if (result != -1)
        printf("\n%d-th smallest element is: %d\n", k, result);
    else
        printf("\nInvalid K value!\n");

    return 0;
}

