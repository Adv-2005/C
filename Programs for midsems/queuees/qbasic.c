#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
int num[MAX];
int rear;
int front;
}queue;

int isFull(queue *qs){
    if(qs->rear==MAX-1)
        return 1;
    else
        return 0;
}
int isEmpty(queue *qs){
    if(qs->front==-1)
        return 1;
    else
        return 0;
}
void insertq(queue *qs, int value){
    if(isFull(qs)){
    printf("Overflow");
}
else{
    qs->num[++qs->rear]=value;
    if(qs->front==-1)
        qs->front=0;
}
}
int deleteq(queue *qs){
if(isEmpty(qs)){
    printf("Underflow\n");
    return -1;}
else if(qs->front==qs->rear){
    int temp= qs->num[qs->front];
    qs->rear=qs->front=-1;
    return temp;
}
else{
    return qs->num[qs->front++];
}
}

void displayq(queue *qs){
int i;
if(qs->front==-1 && qs->rear==-1){
    printf("Queue is Empty");
}
else{
    for(i=qs->front;i<=qs->rear;i++)
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
    insertq(&q,val);break;

case 2:

    del=deleteq(&q);
    if(del!=-1){
    printf("Deleted value: %d\n",del);break;}
case 3:
    printf("Queue:\n");
    displayq(&q);break;
case 4:
    flag=0;
    printf("Exiting queue");break;
default:
    printf("Enter valid choice");
}
}
}

