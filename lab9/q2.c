#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertEnd(Node** head, int data) {
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
}

// Function to check if a value exists in the list
int exists(Node* head, int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Function to perform union operation without header node
Node* unionLists(Node* head1, Node* head2) {
    Node* result = NULL;
    Node* temp = head1;
    while (temp != NULL) {
        insertEnd(&result, temp->data);
        temp = temp->next;
    }
    temp = head2;
    while (temp != NULL) {
        if (!exists(result, temp->data)) {
            insertEnd(&result, temp->data);
        }
        temp = temp->next;
    }
    return result;
}

// Function to perform intersection operation without header node
Node* intersectionLists(Node* head1, Node* head2) {
    Node* result = NULL;
    Node* temp = head1;
    while (temp != NULL) {
        if (exists(head2, temp->data)) {
            insertEnd(&result, temp->data);
        }
        temp = temp->next;
    }
    return result;
}

// Function to perform union operation with header node
Node* unionListsWithHeader(Node* head1, Node* head2) {
    Node* result = createNode(0); // Header node
    Node* temp = head1->next;
    while (temp != NULL) {
        insertEnd(&result, temp->data);
        temp = temp->next;
    }
    temp = head2->next;
    while (temp != NULL) {
        if (!exists(result->next, temp->data)) {
            insertEnd(&result, temp->data);
        }
        temp = temp->next;
    }
    return result;
}

// Function to perform intersection operation with header node
Node* intersectionListsWithHeader(Node* head1, Node* head2) {
    Node* result = createNode(0); // Header node
    Node* temp = head1->next;
    while (temp != NULL) {
        if (exists(head2->next, temp->data)) {
            insertEnd(&result, temp->data);
        }
        temp = temp->next;
    }
    return result;
}

// Function to display the list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Without header node
    Node* head1 = NULL;
    Node* head2 = NULL;

    insertEnd(&head1, 10);
    insertEnd(&head1, 20);
    insertEnd(&head1, 30);

    insertEnd(&head2, 20);
    insertEnd(&head2, 40);
    insertEnd(&head2, 50);

    Node* unionList = unionLists(head1, head2);
    Node* intersectionList = intersectionLists(head1, head2);

    printf("Union without header node: ");
    displayList(unionList);

    printf("Intersection without header node: ");
    displayList(intersectionList);

    // With header node
    Node* head1WithHeader = createNode(0); // Header node
    Node* head2WithHeader = createNode(0); // Header node

    insertEnd(head1WithHeader, 10);
    insertEnd(head1WithHeader, 20);
    insertEnd(head1WithHeader, 30);

    insertEnd(head2WithHeader, 20);
    insertEnd(head2WithHeader, 40);
    insertEnd(head2WithHeader, 50);

    Node* unionListWithHeader = unionListsWithHeader(head1WithHeader, head2WithHeader);
    Node* intersectionListWithHeader = intersectionListsWithHeader(head1WithHeader, head2WithHeader);

    printf("Union with header node: ");
    displayList(unionListWithHeader->next);

    printf("Intersection with header node: ");
    displayList(intersectionListWithHeader->next);

    return 0;
}
