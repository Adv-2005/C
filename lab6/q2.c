#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int i;
void reverse(char *exp);
void infixToPostfix(char *infix, char *postfix);
void infixToPrefix(char *infix, char *prefix);
int precedence(char op);
int isOperator(char ch);
void push(char *stack, int *top, char ch);
char pop(char *stack, int *top);

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}

void reverse(char *exp) {
    int length = strlen(exp);
    for ( i = 0; i < length / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[length - i - 1];
        exp[length - i - 1] = temp;
    }
}


void infixToPostfix(char *infix, char *postfix) {
    char stack[MAX];
    int top = -1;
    int k = 0;

    for ( i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, &top, infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop(stack, &top);
            }
            pop(stack, &top);
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = pop(stack, &top);
            }
            push(stack, &top, infix[i]);
        }
    }

    while (top != -1) {
        postfix[k++] = pop(stack, &top);
    }

    postfix[k] = '\0';
}


void infixToPrefix(char *infix, char *prefix) {
    reverse(infix);
    for ( i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    char postfix[MAX];
    infixToPostfix(infix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}


int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}


int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}


void push(char *stack, int *top, char ch) {
    stack[++(*top)] = ch;
}


char pop(char *stack, int *top) {
    return stack[(*top)--];
}

