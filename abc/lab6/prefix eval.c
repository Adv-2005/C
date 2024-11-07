#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int i;
typedef struct {
    int arr[MAX];
    int top;
} STACK;


void push(STACK *s, int item);
int pop(STACK *s);
int isEmpty(STACK *s);
int isFull(STACK *s);
int evaluatePrefix(char* expression);

int main() {
    char expression[MAX];
    printf("Enter a prefix expression: ");
    scanf("%s", expression);

    int result = evaluatePrefix(expression);
    printf("The result of the prefix expression is: %d\n", result);

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


int evaluatePrefix(char* expression) {
    STACK stack;
    stack.top = -1;
    int length = strlen(expression);

    for ( i = length - 1; i >= 0; i--) {

        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else {

            int operand1 = pop(&stack);
            int operand2 = pop(&stack);


            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }
    return pop(&stack);
}

