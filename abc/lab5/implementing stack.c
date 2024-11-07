#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int i;
typedef struct {
    char arr[MAX];
    int top;
} STACK;


void push(STACK *s, char item);
char pop(STACK *s);
void display(STACK *s);
int isEmpty(STACK *s);
int isFull(STACK *s);

int main() {
    STACK stack;
    stack.top = -1;
    int choice;
    char item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull(&stack)) {
                    printf("Stack Overflow!\n");
                } else {
                    printf("Enter the character to push: ");
                    scanf(" %c", &item);
                    push(&stack, item);
                }
                break;
            case 2:
                if (isEmpty(&stack)) {
                    printf("Stack Underflow!\n");
                } else {
                    item = pop(&stack);
                    printf("Popped item: %c\n", item);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
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


void display(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements:\n");
        for ( i = s->top; i >= 0; i--) {
            printf("%c\n", s->arr[i]);
        }
    }
}


int isEmpty(STACK *s) {
    return s->top == -1;
}


int isFull(STACK *s) {
    return s->top == MAX - 1;
}
