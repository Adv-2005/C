
#include <stdio.h>
#include <stdlib.h>

#define MAX 100


typedef struct {
    int arr[MAX];
    int top;
} STACK;


void push(STACK *s, int item);
int pop(STACK *s);
int isEmpty(STACK *s);
int isFull(STACK *s);
void convertToBinary(int decimal);

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Binary equivalent: ");
    convertToBinary(decimal);

    return 0;
}


void push(STACK *s, int item) {
    if (!isFull(s)) {
        s->arr[++(s->top)] = item;
    }
}


int pop(STACK *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return -1;
}


int isEmpty(STACK *s) {
    return s->top == -1;
}


int isFull(STACK *s) {
    return s->top == MAX - 1;
}


void convertToBinary(int decimal) {
    STACK stack;
    stack.top = -1;

    while (decimal > 0) {
        push(&stack, decimal % 2);
        decimal /= 2;
    }

    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}
