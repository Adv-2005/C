#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
int num[MAX];
int rear;
int front;
}queue;
int isFull(queue *qs){
    if(qs->rear==MAX-1){
        return 1;
    }
    else
        return 0;
}
int isEmpty(queue *qs){
    if(qs->rear==qs->front)
        return 1;
    else
        return 0;
}
void enqueue(queue *qs, int value){
    if(isFull(qs)){
        printf("Overflow");
    }
    else{
        qs->num[++qs->rear]=value;
    }
}
int dequeue(queue *qs){
    int a=-1;
    if(isEmpty(qs)){
        printf("Underflow");
    }
    else{
        qs->front++;
        a=qs->num[qs->front];
    }
    return a;
}
void display(queue *qs){
    int i;
    if(isEmpty(qs)){
        printf("Underflow");
    }
    else if(isFull(qs)){
        printf("Overflow");
    }
    else{
        for(i=qs->front+1;i<=qs->rear;i++)
            printf("%d ",qs->num[i]);
    }
}

void main(){
    queue q;
    q.rear=q.front=-1;
    int c,flag=1,val,del;

while(flag){
printf("\nEnter choice:\n");
printf("1:Insert \n 2:Delete\n 3:Display\n 4:exit\n");
scanf("%d",&c);
switch(c){
case 1:

    printf("Enter element to insert\n");
    scanf("%d",&val);
    enqueue(&q,val);break;

case 2:

    del=dequeue(&q);
    if(del!=-1){
    printf("Deleted value: %d\n",del);break;}
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


