#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to create a circular doubly linked list with a header node
Node* createList() {
    Node* header = createNode(0); // Header node
    header->next = header->prev = header;
    return header;
}

// Function to insert a node at the end
void insertEnd(Node* header, int data) {
    Node* newNode = createNode(data);
    Node* last = header->prev;

    newNode->next = header;
    header->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
}

// Function to display the list
void displayList(Node* header) {
    Node* temp = header->next;
    while (temp != header) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two numbers represented by circular doubly linked lists
Node* addNumbers(Node* header1, Node* header2) {
    Node* result = createList();
    Node* temp1 = header1->prev; // Start from the least significant digit
    Node* temp2 = header2->prev;
    int carry = 0;

    while (temp1 != header1 || temp2 != header2 || carry != 0) {
        int sum = carry;
        if (temp1 != header1) {
            sum += temp1->data;
            temp1 = temp1->prev;
        }
        if (temp2 != header2) {
            sum += temp2->data;
            temp2 = temp2->prev;
        }
        carry = sum / 10;
        insertEnd(result, sum % 10);
    }

    // Reverse the result list to get the correct order
    Node* current = result->next;
    Node* prev = result;
    Node* next;
    while (current != result) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    result->next = prev;
    result->prev = prev->prev;
    prev->prev->next = result;
    prev->prev = result;

    return result;
}

int main() {
    Node* num1 = createList();
    Node* num2 = createList();

    // Example numbers: 12345 and 6789
    insertEnd(num1, 5);
    insertEnd(num1, 4);
    insertEnd(num1, 3);
    insertEnd(num1, 2);
    insertEnd(num1, 1);

    insertEnd(num2, 9);
    insertEnd(num2, 8);
    insertEnd(num2, 7);
    insertEnd(num2, 6);

    printf("Number 1: ");
    displayList(num1);

    printf("Number 2: ");
    displayList(num2);

    Node* result = addNumbers(num1, num2);

    printf("Sum: ");
    displayList(result);

    return 0;
}
