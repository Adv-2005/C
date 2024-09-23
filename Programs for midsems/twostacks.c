#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct{
    int num[MAX];
    int top1;
    int top2;
} twostacks;

void init(twostacks *ps) {
    ps->top1 = -1;           // Stack 1 starts from the beginning
    ps->top2 = MAX;          // Stack 2 starts from the end
}

// Push into Stack 1
void push1(twostacks *ps, int value) {
    if (ps->top1 < ps->top2 - 1) {  // Check if space is available
        ps->num[++ps->top1] = value;
    } else {
        printf("Stack 1 is Full\n");
    }
}

// Push into Stack 2
void push2(twostacks *ps, int value) {
    if (ps->top1 < ps->top2 - 1) {  // Check if space is available
        ps->num[--ps->top2] = value;
    } else {
        printf("Stack 2 is Full\n");
    }
}

// Pop from Stack 1
int pop1(twostacks *ps) {
    if (ps->top1 >= 0) {
        return ps->num[ps->top1--];
    } else {
        printf("Stack 1 Underflow\n");
        return -1;
    }
}

// Pop from Stack 2
int pop2(twostacks *ps) {
    if (ps->top2 < MAX) {
        return ps->num[ps->top2++];
    } else {
        printf("Stack 2 Underflow\n");
        return -1;
    }
}

// Display Stack 1
void displayStack1(twostacks *ps) {
    if (ps->top1 >= 0) {
        printf("Stack 1: ");
        for (int i = 0; i <= ps->top1; i++)
            printf("%d ", ps->num[i]);
        printf("\n");
    } else {
        printf("Stack 1 Underflow\n");
    }
}

// Display Stack 2
void displayStack2(twostacks *ps) {
    if (ps->top2 < MAX) {
        printf("Stack 2: ");
        for (int i = ps->top2; i < MAX; i++)
            printf("%d ", ps->num[i]);
        printf("\n");
    } else {
        printf("Stack 2 Underflow\n");
    }
}

int main() {
    twostacks ps;
    init(&ps);

    // Pushing values into Stack 1
    push1(&ps, 1);
    push1(&ps, 2);
    push1(&ps, 3);

    // Pushing values into Stack 2
    push2(&ps, 4);
    push2(&ps, 5);
    push2(&ps, 6);

    // Pop from both stacks
    printf("Popped from Stack 1: %d\n", pop1(&ps));
    printf("Popped from Stack 2: %d\n", pop2(&ps));

    // Display both stacks
    displayStack1(&ps);
    displayStack2(&ps);

    return 0;
}
