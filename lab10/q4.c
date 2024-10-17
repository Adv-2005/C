
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to create a circular linked list with a header node
Node* createList() {
    Node* header = createNode(0, 0); // Header node
    header->next = header;
    return header;
}

// Function to insert a term into the polynomial
void insertTerm(Node* header, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    Node* temp = header;
    while (temp->next != header && temp->next->exp > exp) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the polynomial
void displayPolynomial(Node* header) {
    Node* temp = header->next;
    while (temp != header) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != header) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to subtract two polynomials
Node* subtractPolynomials(Node* header1, Node* header2) {
    Node* result = createList();
    Node* temp1 = header1->next;
    Node* temp2 = header2->next;

    while (temp1 != header1 && temp2 != header2) {
        if (temp1->exp > temp2->exp) {
            insertTerm(result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else if (temp1->exp < temp2->exp) {
            insertTerm(result, -temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        } else {
            int coeff = temp1->coeff - temp2->coeff;
            if (coeff != 0) {
                insertTerm(result, coeff, temp1->exp);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != header1) {
        insertTerm(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != header2) {
        insertTerm(result, -temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

// Function to multiply two polynomials
Node* multiplyPolynomials(Node* header1, Node* header2) {
    Node* result = createList();
    Node* temp1 = header1->next;
    Node* temp2;

    while (temp1 != header1) {
        temp2 = header2->next;
        while (temp2 != header2) {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            insertTerm(result, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return result;
}

// Main function with menu
int main() {
    Node* poly1 = createList();
    Node* poly2 = createList();
    Node* result;
    int choice, coeff, exp;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Input polynomial 1\n");
        printf("2. Input polynomial 2\n");
        printf("3. Subtract polynomials\n");
        printf("4. Multiply polynomials\n");
        printf("5. Display polynomial 1\n");
        printf("6. Display polynomial 2\n");
        printf("7. Display result\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter coefficient and exponent (enter -1 -1 to stop): ");
                while (1) {
                    scanf("%d %d", &coeff, &exp);
                    if (coeff == -1 && exp == -1) break;
                    insertTerm(poly1, coeff, exp);
                }
                break;
            case 2:
                printf("Enter coefficient and exponent (enter -1 -1 to stop): ");
                while (1) {
                    scanf("%d %d", &coeff, &exp);
                    if (coeff == -1 && exp == -1) break;
                    insertTerm(poly2, coeff, exp);
                }
                break;
            case 3:
                result = subtractPolynomials(poly1, poly2);
                printf("Subtraction result: ");
                displayPolynomial(result);
                break;
            case 4:
                result = multiplyPolynomials(poly1, poly2);
                printf("Multiplication result: ");
                displayPolynomial(result);
                break;
            case 5:
                printf("Polynomial 1: ");
                displayPolynomial(poly1);
                break;
            case 6:
                printf("Polynomial 2: ");
                displayPolynomial(poly2);
                break;
            case 7:
                printf("Result: ");
                displayPolynomial(result);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
