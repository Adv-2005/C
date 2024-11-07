#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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

typedef struct {
    Stack stack1;
    Stack stack2;
} Queue;

void enqueue(Queue *q, int value) {
    push(&(q->stack1), value);
}

int dequeue(Queue *q) {
    if (isEmpty(&(q->stack2))) {
        while (!isEmpty(&(q->stack1))) {
            push(&(q->stack2), pop(&(q->stack1)));
        }
    }
    return pop(&(q->stack2));
}

int main() {
    Queue q;
    q.stack1.top = -1;
    q.stack2.top = -1;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}

