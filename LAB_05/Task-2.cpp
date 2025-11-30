#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef, power;
    struct Node *next;
};

void insertTerm(struct Node **poly, int coef, int power) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->power = power;
    newNode->next = *poly;
    *poly = newNode;
}

void display(struct Node *poly) {
    while(poly) {
        printf("%dx^%d", poly->coef, poly->power);
        if(poly->next) printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    struct Node *poly = NULL;
    int coef, pow;

    insertTerm(&poly, 3, 2);
    insertTerm(&poly, 5, 1);

    printf("Current Polynomial: ");
    display(poly);

    printf("\nEnter coefficient and power to add: ");
    scanf("%d %d", &coef, &pow);

    insertTerm(&poly, coef, pow);

    printf("Updated Polynomial: ");
    display(poly);

    return 0;
}

