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

struct Node* mergeSorted(struct Node *l1, struct Node *l2) {
    struct Node dummy;
    struct Node *tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL, *mergedList = NULL;

    insert(&list1, 50);
    insert(&list1, 30);
    insert(&list1, 10);

    insert(&list2, 60);
    insert(&list2, 40);
    insert(&list2, 20);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    mergedList = mergeSorted(list1, list2);

    printf("\nMerged Sorted List:\n");
    display(mergedList);

    return 0;
}

