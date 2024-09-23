#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>

typedef struct{
    Stack s1;
    Stack s2;
}Queue;

void enqueue(Queue *q,int ele){
    while(!isEmpty(&(q->s1))){
        push(&(q->s2),pop(&(q->s1)));
    }

    push(&(q->s1),ele);

    while(!isEmpty(&(q->s2))){
        push(&(q->s1),pop(&(q->s2)));
    }
}

void dequeue(Queue *q){
    pop(&(q->s1));
}

void printQ(Queue *q){
    int i;
    for(i=0;i<=(q->s1.top);i++){
        printf("%d  ",q->s1.arr[i]);
    }
}

// void printQ(Queue *q){
//     print(&(q->s1));
// }

int main(){
    Queue q;
    q.s1.top = q.s2.top = -1;

    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    dequeue(&q);
    
    printQ(&q);
}