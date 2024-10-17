#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation error\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue an element
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to display the queue
void displayQueue(Queue* queue) {
    Node* temp = queue->front;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    displayQueue(queue);
    printf("Dequeued: %d\n", dequeue(queue));
    displayQueue(queue);
    return 0;
}
