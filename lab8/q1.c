
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int i;
typedef struct {
    int data[MAX];
    int priority[MAX];
    int size;
} PriorityQueue;

void insert(PriorityQueue *pq, int value, int priority) {
    if (pq->size == MAX) {
        printf("Priority Queue is full\n");
        return;
    }
    int i = pq->size - 1;
    while (i >= 0 && pq->priority[i] > priority) {
        pq->data[i + 1] = pq->data[i];
        pq->priority[i + 1] = pq->priority[i];
        i--;
    }
    pq->data[i + 1] = value;
    pq->priority[i + 1] = priority;
    pq->size++;
}

int deleteMin(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    int minValue = pq->data;
    for ( i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }
    pq->size--;
    return minValue;
}

void display(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }
    for ( i = 0; i < pq->size; i++) {
        printf("Value: %d, Priority: %d\n", pq->data[i], pq->priority[i]);
    }
}

int main() {
    PriorityQueue pq;
    pq.size = 0;

    insert(&pq, 10, 2);
    insert(&pq, 20, 1);
    insert(&pq, 30, 3);

    printf("Priority Queue:\n");
    display(&pq);

    printf("Deleted element with highest priority: %d\n", deleteMin(&pq));

    printf("Priority Queue after deletion:\n");
    display(&pq);

    return 0;
}
