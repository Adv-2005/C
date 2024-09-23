#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100


typedef struct{
    int f;
    int r;
    int arr[MAX];
}Queue;

typedef struct{
    Queue q1;
    Queue q2;
}Stack;

bool isFull(Queue *q){
    if(q->r == MAX-1){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(Queue *q){
    if(q->f > q->r || q->f == -1){
        return true;
    }else{
        return false;
    }
}

void enqueue(Queue *q,int ele){
    if(!isFull(q)){

        if(q->f == -1){
            q->f =0;
        }

        q->r++;
        q->arr[q->r] = ele;
    }else{
        printf("Stack Overflow!");
    }
}

int dequeue(Queue *q){
    if(!isEmpty(q)){
        int a = q->arr[q->f];
        // printf("dequeued : %d\n ",a);
        q->f++;
        return a;

    }else{
        printf("Stack Underflow!");
    }
}

void print(Queue *q){
    int i = q->f;
    for(i;i<=q->r;i++){
        printf("%d ",q->arr[i]);
    }

    printf("\n");
}



void push(Stack *s,int ele){
    enqueue(&(s->q2),ele);

    while(!isEmpty(&(s->q1))){
        enqueue(&(s->q2),dequeue(&(s->q1)));
    }

    while(!isEmpty(&(s->q2))){
        enqueue(&(s->q1),dequeue(&(s->q2)));

    }
}

int pop(Stack *s){
    dequeue(&(s->q1));
}


int main(){
    Stack s;
    s.q1.f = s.q1.r = s.q2.f = s.q2.r = -1;

    push(&s,50);
    push(&s,60);
    push(&s,70);

    pop(&s);


    print(&(s.q1));

    
}