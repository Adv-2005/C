#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
int size;
char *arr;
int rear;
int front;
}Cirqueue;
int isFull(Cirqueue *qs){
    if(((qs->rear+1)%qs->size)==qs->front){
        return 1;
    }
    else
        return 0;
}
int isEmpty(Cirqueue *qs){
    if(qs->rear==qs->front)
        return 1;
    else
        return 0;
}
void enqueue(Cirqueue *qs, char value){
    if(isFull(qs)){
        printf("Overflow");
    }
    else{
        qs->rear=(qs->rear+1)%qs->size;
        qs->arr[qs->rear]=value;
    }
}
int dequeue(Cirqueue *qs){
    int a=-1;
    if(isEmpty(qs)){
        printf("Underflow");
    }
    else{
        qs->front=(qs->front+1)%qs->size;
        a=qs->arr[qs->front];
    }
    return a;
}
void display(Cirqueue *qs){
    int i;
    if(isEmpty(qs)){
        printf("Underflow");
    }
    else{
        int i = (qs->front + 1) % qs->size;
    while (i != (qs->rear + 1) % qs->size) {
        printf("%c ", qs->arr[i]);
        i = (i + 1) % qs->size;
    }

}
}

void main(){
    Cirqueue q;
    q.size=4;
    q.rear=q.front=0;
    int c,flag=1,val,del;
    q.arr=(char*)malloc(q.size*sizeof(char));

while(flag){
printf("\nEnter choice:\n");
printf("1:Insert \n 2:Delete\n 3:Display\n 4:exit\n");
scanf("%d",&c);
switch(c){
case 1:

    printf("Enter element to insert\n");
    scanf(" %c",&val);
    enqueue(&q,val);break;

case 2:

    del=dequeue(&q);
    if(del!=-1){
    printf("Deleted value: %c\n",del);break;}
case 3:
    printf("Queue:\n");
    display(&q);break;
case 4:
    flag=0;
    printf("Exiting queue");break;
default:
    printf("Enter valid choice");
}
}
}



