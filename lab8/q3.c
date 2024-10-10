
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int i;
typedef struct {
    char data[MAX];
    int front;
    int rear;
} Deque;

void insertRear(Deque *dq, char value) {
    if ((dq->rear + 1) % MAX == dq->front) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
    }
    dq->rear = (dq->rear + 1) % MAX;
    dq->data[dq->rear] = value;
}

char deleteFront(Deque *dq) {
    if (dq->front == -1) {
        printf("Deque is empty\n");
        return '\0';
    }
    char value = dq->data[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }
    return value;
}

char deleteRear(Deque *dq) {
    if (dq->rear == -1) {
        printf("Deque is empty\n");
        return '\0';
    }
    char value = dq->data[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
    return value;
}

int isPalindrome(char *str) {
    Deque dq;
    dq.front = dq.rear = -1;

    int len = strlen(str);
    for ( i = 0; i < len; i++) {
        insertRear(&dq, str[i]);
    }

    while (dq.front != dq.rear && dq.front != (dq.rear + 1) % MAX) {
        if (deleteFront(&dq) != deleteRear(&dq)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
