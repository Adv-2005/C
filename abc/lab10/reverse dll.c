#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertEnd(Node** head, char* data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the doubly linked list
void reverseList(Node** head) {
    Node* temp = NULL;
    Node* current = *head;

    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Before changing the head, check for the cases like empty list and list with only one node
    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main() {
    Node* head = NULL;

    // Example words
    insertEnd(&head, "Hello");
    insertEnd(&head, "world");
    insertEnd(&head, "this");
    insertEnd(&head, "is");
    insertEnd(&head, "a");
    insertEnd(&head, "test");

    printf("Original list: ");
    displayList(head);

    reverseList(&head);

    printf("Reversed list: ");
    displayList(head);

    return 0;
}
