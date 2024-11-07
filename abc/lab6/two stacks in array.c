#include <stdio.h>
#include <stdlib.h>

#define MAX 100


typedef struct {
    int arr[MAX];
    int top1;
    int top2;
} TwoStacks;


void push1(TwoStacks *s, int item);
void push2(TwoStacks *s, int item);
int pop1(TwoStacks *s);
int pop2(TwoStacks *s);
int isEmpty1(TwoStacks *s);
int isEmpty2(TwoStacks *s);
int isFull(TwoStacks *s);

int main() {
    TwoStacks stacks;
    stacks.top1 = -1;
    stacks.top2 = MAX;


    push1(&stacks, 10);
    push2(&stacks, 20);
    push1(&stacks, 30);
    push2(&stacks, 40);

    printf("Popped from stack 1: %d\n", pop1(&stacks));
    printf("Popped from stack 2: %d\n", pop2(&stacks));

    return 0;
}

void push1(TwoStacks *s, int item) {
    if (!isFull(s)) {
        s->arr[++(s->top1)] = item;
    } else {
        printf("Stack Overflow!\n");
    }
}

void push2(TwoStacks *s, int item) {
    if (!isFull(s)) {
        s->arr[--(s->top2)] = item;
    } else {
        printf("Stack Overflow!\n");
    }
}


int pop1(TwoStacks *s) {
    if (!isEmpty1(s)) {
        return s->arr[(s->top1)--];
    } else {
        printf("Stack Underflow!\n");
        return -1;
    }
}

int pop2(TwoStacks *s) {
    if (!isEmpty2(s)) {
        return s->arr[(s->top2)++];
    } else {
        printf("Stack Underflow!\n");
        return -1;
    }
}

int isEmpty1(TwoStacks *s) {
    return s->top1 == -1;
}

int isEmpty2(TwoStacks *s) {
    return s->top2 == MAX;
}

int isFull(TwoStacks *s) {
    return s->top1 + 1 == s->top2;
}
