#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int power;
    struct Node *next;
};

void insertTerm(struct Node **poly, int coef, int power) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->power = power;
    newNode->next = NULL;

    if (*poly == NULL || (*poly)->power < power) {
        newNode->next = *poly;
        *poly = newNode;
        return;
    }

    struct Node *temp = *poly;
    while (temp->next && temp->next->power > power)
        temp = temp->next;

    if (temp->power == power) {
        temp->coef += coef;
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void display(struct Node *poly) {
    while (poly) {
        printf("%dx^%d", poly->coef, poly->power);
        poly = poly->next;
        if (poly) printf(" + ");
    }
    printf("\n");
}

struct Node* addPoly(struct Node *a, struct Node *b) {
    struct Node *result = NULL;
    while (a || b) {
        if (a && (!b || a->power > b->power)) {
            insertTerm(&result, a->coef, a->power);
            a = a->next;
        } else if (b && (!a || b->power > a->power)) {
            insertTerm(&result, b->coef, b->power);
            b = b->next;
        } else {
            insertTerm(&result, a->coef + b->coef, a->power);
            a = a->next;
            b = b->next;
        }
    }
    return result;
}

struct Node* subPoly(struct Node *a, struct Node *b) {
    struct Node *result = NULL;
    while (a || b) {
        if (a && (!b || a->power > b->power)) {
            insertTerm(&result, a->coef, a->power);
            a = a->next;
        } else if (b && (!a || b->power > a->power)) {
            insertTerm(&result, -b->coef, b->power);
            b = b->next;
        } else {
            insertTerm(&result, a->coef - b->coef, a->power);
            a = a->next;
            b = b->next;
        }
    }
    return result;
}

struct Node* multiplyPoly(struct Node *a, struct Node *b) {
    struct Node *result = NULL;
    while (a) {
        struct Node *temp = b;
        while (temp) {
            insertTerm(&result, a->coef * temp->coef, a->power + temp->power);
            temp = temp->next;
        }
        a = a->next;
    }
    return result;
}

int main() {
    struct Node *p1 = NULL, *p2 = NULL, *result = NULL;
    int choice;

    insertTerm(&p1, 4, 2);
    insertTerm(&p1, 3, 1);

    insertTerm(&p2, 2, 2);
    insertTerm(&p2, 1, 0);

    printf("Polynomial 1: ");
    display(p1);
    printf("Polynomial 2: ");
    display(p2);

    printf("\n0: Addition\n1: Subtraction\n2: Division (Not Implemented)\n3: Multiplication\nEnter Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 0: result = addPoly(p1, p2); break;
        case 1: result = subPoly(p1, p2); break;
        case 2: printf("\nDivision not implemented.\n"); break;
        case 3: result = multiplyPoly(p1, p2); break;
        default: printf("\nInvalid Choice\n");
    }

    if (result) {
        printf("\nResult Polynomial: ");
        display(result);
    }

    return 0;
}

