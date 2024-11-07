#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void enqueue(Queue *q, int value) {
    if ((q->rear + 1) % MAX == q->front) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
}

int dequeue(Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

int empty(Queue *q) {
    return q->front == -1;
}

typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void reverseQueue(Queue *q) {
    Stack s;
    s.top = -1;

    while (!empty(q)) {
        push(&s, dequeue(q));
    }

    while (!isEmpty(&s)) {
        enqueue(q, pop(&s));
    }
}

void displayQueue(Queue *q) {
    if (empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue q;
    q.front = q.rear = -1;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("Original Queue: ");
    displayQueue(&q);

    reverseQueue(&q);

    printf("Reversed Queue: ");
    displayQueue(&q);

    return 0;
}

