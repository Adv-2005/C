
#include <stdio.h>
#include <stdlib.h>
int i;
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

// Function to merge two sorted linked lists
Node* mergeLists(Node* head1, Node* head2) {
    Node* mergedHead = NULL;
    Node** lastPtrRef = &mergedHead;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            *lastPtrRef = head1;
            head1 = head1->next;
        } else {
            *lastPtrRef = head2;
            head2 = head2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    if (head1 != NULL) {
        *lastPtrRef = head1;
    } else {
        *lastPtrRef = head2;
    }

    return mergedHead;
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
    int N1, N2, data;
    Node* classA = NULL;
    Node* classB = NULL;

    printf("Enter the number of students in class A and class B: ");
    scanf("%d %d", &N1, &N2);

    printf("Enter the heights of students in class A: ");
    for ( i = 0; i < N1; i++) {
        scanf("%d", &data);
        insertEnd(&classA, data);
    }

    printf("Enter the heights of students in class B: ");
    for ( i = 0; i < N2; i++) {
        scanf("%d", &data);
        insertEnd(&classB, data);
    }

    printf("Line of Class A: ");
    displayList(classA);

    printf("Line of Class B: ");
    displayList(classB);

    Node* mergedClass = mergeLists(classA, classB);

    printf("Joint line of both classes: ");
    displayList(mergedClass);

    return 0;
}
