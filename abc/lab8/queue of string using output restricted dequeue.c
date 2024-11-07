
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char *data[MAX];
    int front;
    int rear;
} Deque;

void insertFront(Deque *dq, char *value) {
    if ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->data[dq->front] = (char *)malloc(strlen(value) + 1);
    strcpy(dq->data[dq->front], value);
}

void insertRear(Deque *dq, char *value) {
    if ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->data[dq->rear] = (char *)malloc(strlen(value) + 1);
    strcpy(dq->data[dq->rear], value);
}

char* deleteFront(Deque *dq) {
    if (dq->front == -1) {
        printf("Deque is empty\n");
        return NULL;
    }
    char *value = dq->data[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
    return value;
}

void display(Deque *dq) {
    if (dq->front == -1) {
        printf("Deque is empty\n");
        return;
    }
    int i = dq->front;
    while (1) {
        printf("%s ", dq->data[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    dq.front = dq.rear = -1;

    insertRear(&dq, "Hello");
    insertRear(&dq, "World");
    insertFront(&dq, "Start");
    insertRear(&dq, "Queue");

    printf("Queue: ");
    display(&dq);

    printf("Deleted: %s\n", deleteFront(&dq));
    printf("Queue after deletion: ");
    display(&dq);

    return 0;
}
