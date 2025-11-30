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
    } 
    else {
        struct Node *temp = *poly;
        while (temp->next != NULL && temp->next->power > power)
            temp = temp->next;

        if (temp->power == power) {
            temp->coef += coef;
            free(newNode);
        } 
        else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void display(struct Node *poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coef, poly->power);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

struct Node* addPoly(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;

    while (p1 && p2) {
        if (p1->power > p2->power) {
            insertTerm(&result, p1->coef, p1->power);
            p1 = p1->next;
        }
        else if (p1->power < p2->power) {
            insertTerm(&result, p2->coef, p2->power);
            p2 = p2->next;
        }
        else {
            insertTerm(&result, p1->coef + p2->coef, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1) {
        insertTerm(&result, p1->coef, p1->power);
        p1 = p1->next;
    }

    while (p2) {
        insertTerm(&result, p2->coef, p2->power);
        p2 = p2->next;
    }

    return result;
}

struct Node* subPoly(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;

    while (p2) {
        insertTerm(&result, -(p2->coef), p2->power);
        p2 = p2->next;
    }

    return addPoly(p1, result);
}

struct Node* multiplyPoly(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;

    struct Node *t1 = p1, *t2;

    while (t1) {
        t2 = p2;
        while (t2) {
            insertTerm(&result, t1->coef * t2->coef, t1->power + t2->power);
            t2 = t2->next;
        }
        t1 = t1->next;
    }

    return result;
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL;
    struct Node *addResult, *subResult, *mulResult;

    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 2, 0);

    insertTerm(&poly2, 4, 2);
    insertTerm(&poly2, 5, 1);
    insertTerm(&poly2, 6, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    addResult = addPoly(poly1, poly2);
    printf("\nAddition: ");
    display(addResult);

    subResult = subPoly(poly1, poly2);
    printf("Subtraction: ");
    display(subResult);

    mulResult = multiplyPoly(poly1, poly2);
    printf("Multiplication: ");
    display(mulResult);

    return 0;
}

