#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
    char *queue[MAX];
    int front;
    int rear;
} CircularQueue;

void insertcq(CircularQueue *cq, char *str) {
    if ((cq->rear + 1) % MAX == cq->front) {
        printf("Queue is full\n");
        return;
    }
    cq->rear = (cq->rear + 1) % MAX;
    cq->queue[cq->rear] = (char *)malloc(strlen(str) + 1);
    strcpy(cq->queue[cq->rear], str);
    if (cq->front == -1) {
        cq->front = 0;
    }
}

void deletecq(CircularQueue *cq) {
    if (cq->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    free(cq->queue[cq->front]);
    if (cq->front == cq->rear) {
        cq->front = cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % MAX;
    }
}

void displaycq(CircularQueue *cq) {
    if (cq->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = cq->front;
    while (1) {
        printf("%s ", cq->queue[i]);
        if (i == cq->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CircularQueue cq;
    cq.front = cq.rear = -1;

    insertcq(&cq, "Hello");
    insertcq(&cq, "World");
    insertcq(&cq, "Circular");
    insertcq(&cq, "Queue");
    insertcq(&cq, "Test");

    displaycq(&cq);

    deletecq(&cq);
    displaycq(&cq);

    insertcq(&cq, "Again");
    displaycq(&cq);

    return 0;
}

