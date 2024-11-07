#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct {
    int arr[N];
    int front1, rear1;
    int front2, rear2;
} DualCircularQueue;

void insertcq1(DualCircularQueue *dq, int value) {
    if ((dq->rear1 + 1) % (N/2 + 1) == dq->front1) {
        printf("Queue 1 is full\n");
        return;
    }
    dq->rear1 = (dq->rear1 + 1) % (N/2 + 1);
    dq->arr[dq->rear1] = value;
    if (dq->front1 == -1) {
        dq->front1 = 0;
    }
}

void insertcq2(DualCircularQueue *dq, int value) {
    if ((dq->rear2 + 1) % (N/2 + 1) == dq->front2) {
        printf("Queue 2 is full\n");
        return;
    }
    dq->rear2 = (dq->rear2 + 1) % (N/2 + 1) + N/2 + 1;
    dq->arr[dq->rear2] = value;
    if (dq->front2 == -1) {
        dq->front2 = N/2 + 1;
    }
}

void deletecq1(DualCircularQueue *dq) {
    if (dq->front1 == -1) {
        printf("Queue 1 is empty\n");
        return;
    }
    if (dq->front1 == dq->rear1) {
        dq->front1 = dq->rear1 = -1;
    } else {
        dq->front1 = (dq->front1 + 1) % (N/2 + 1);
    }
}

void deletecq2(DualCircularQueue *dq) {
    if (dq->front2 == -1) {
        printf("Queue 2 is empty\n");
        return;
    }
    if (dq->front2 == dq->rear2) {
        dq->front2 = dq->rear2 = -1;
    } else {
        dq->front2 = (dq->front2 + 1) % (N/2 + 1) + N/2 + 1;
    }
}

void displaycq1(DualCircularQueue *dq) {
    if (dq->front1 == -1) {
        printf("Queue 1 is empty\n");
        return;
    }
    int i = dq->front1;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear1) break;
        i = (i + 1) % (N/2 + 1);
    }
    printf("\n");
}

void displaycq2(DualCircularQueue *dq) {
    if (dq->front2 == -1) {
        printf("Queue 2 is empty\n");
        return;
    }
    int i = dq->front2;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear2) break;
        i = (i + 1) % (N/2 + 1) + N/2 + 1;
    }
    printf("\n");
}

int main() {
    DualCircularQueue dq;
    dq.front1 = dq.rear1 = -1;
    dq.front2 = dq.rear2 = -1;

    insertcq1(&dq, 1);
    insertcq1(&dq, 2);
    insertcq1(&dq, 3);
    insertcq1(&dq, 4);
    insertcq1(&dq, 5);

    insertcq2(&dq, 6);
    insertcq2(&dq, 7);
    insertcq2(&dq, 8);
    insertcq2(&dq, 9);
    insertcq2(&dq, 10);

    printf("Queue 1: ");
    displaycq1(&dq);

    printf("Queue 2: ");
    displaycq2(&dq);

    deletecq1(&dq);
    deletecq2(&dq);

    printf("Queue 1 after deletion: ");
    displaycq1(&dq);

    printf("Queue 2 after deletion: ");
    displaycq2(&dq);

    return 0;
}

