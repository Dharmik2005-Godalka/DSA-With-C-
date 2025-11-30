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

void display(struct Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* waveSort(struct Node *head) {
    if (!head || !head->next) return head;

    struct Node *curr = head;
    int toggle = 0;

    while (curr && curr->next) {
        if ((toggle == 0 && curr->data > curr->next->data) ||
            (toggle == 1 && curr->data < curr->next->data)) {
            int temp = curr->data;
            curr->data = curr->next->data;
            curr->next->data = temp;
        }
        toggle = !toggle;
        curr = curr->next;
    }
    return head;
}

int main() {
    struct Node *head = NULL;

    insert(&head, 70);
    insert(&head, 60);
    insert(&head, 50);
    insert(&head, 40);
    insert(&head, 30);

    printf("\nOriginal Sorted List:\n");
    display(head);

    head = waveSort(head);

    printf("\nWave Sorted List:\n");
    display(head);

    return 0;
}

