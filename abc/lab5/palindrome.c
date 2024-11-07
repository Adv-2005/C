#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int i;
typedef struct {
    char arr[MAX];
    int top;
} STACK;


void push(STACK *s, char item);
char pop(STACK *s);
int isEmpty(STACK *s);
int isFull(STACK *s);
int isPalindrome(char str[]);

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}


void push(STACK *s, char item) {
    if (!isFull(s)) {
        s->arr[++(s->top)] = item;
    }
}


char pop(STACK *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0';
}


int isEmpty(STACK *s) {
    return s->top == -1;
}


int isFull(STACK *s) {
    return s->top == MAX - 1;
}


int isPalindrome(char str[]) {
    int length = strlen(str);
    STACK stack;
    stack.top = -1;


    for ( i = 0; i < length; i++) {
        push(&stack, str[i]);
    }

    for ( i = 0; i < length; i++) {
        if (str[i] != pop(&stack)) {
            return 0;
        }
    }

    return 1;
}
