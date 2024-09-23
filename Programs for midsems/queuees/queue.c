#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    int *arr;
    int f;
    int r;
}Queue;

bool isFull(Queue *q){
    if(q->r == MAX-1){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(Queue *q){
    if(q->f == -1 || q->f > q->r){
        return true;
    }else{
        return false;
    }
}

void enqueueR(Queue *q, int ele){
    if(isFull(q)){
        printf("Queue Overflow!\n");
    }else{
        if(q->f == -1){
            q->f = 0;
        }
        q->r++;
        q->arr[q->r] = ele;
        printf("Enqueued : %d\n", ele);
    }
}

int dequeueF(Queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow!\n");
        return -1;
    }else{
        int dequeuedEle = q->arr[q->f];
        q->f++;
        printf("Dequeued : %d\n", dequeuedEle);
        return dequeuedEle;
    }
}

void enqueueF(Queue *q, int ele){
    if(isFull(q)){
        printf("Queue Overflow!\n");
    }else if(q->f > 0){
        q->f--;
        q->arr[q->f] = ele;
        printf("Enqueued at front : %d\n", ele);
    }else{
        printf("Cannot enqueue at front. Front is at the beginning.\n");
    }
}

int dequeueR(Queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow!\n");
        return -1;
    }else{
        int dequeuedEle = q->arr[q->r];
        q->r--;
        printf("Dequeued at rear : %d\n", dequeuedEle);
        return dequeuedEle;
    }
}

void print(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    int i = q->f;
    for(i; i <= q->r; i++){
        printf("%d, ", q->arr[i]);
    }
    printf("\n");
}

int main(){
    Queue q;
    q.arr = (int *) malloc(sizeof(int) * MAX);
    q.r = -1;
    q.f = -1;

    enqueueR(&q, 1);
    enqueueR(&q, 2);
    enqueueR(&q, 3);
    print(&q);
    dequeueF(&q);
    print(&q);
    enqueueF(&q, 9);
    print(&q);
    dequeueR(&q);
    print(&q);

    free(q.arr);
    return 0;
}