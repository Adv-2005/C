#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
int bin[MAX];
int top;
}stack;
void push(stack *ps , int value){
    if(isFull(ps)){
        printf("Stack Overflow");
    }
    else{
        ps->bin[++(ps->top)]=value;
    }
}
int isFull(stack *ps){
if(ps->top==MAX-1){
    return 1;
}
else{
    return 0;
}
}

int pop(stack *ps){
if(isEmpty(ps)){
    printf("Stack underflow!");
}
else{
    return(ps->bin[ps->top--]);
}
}

int isEmpty(stack *ps){
    if(ps->top==-1){
        return 1;
    }
    else
        return 0;
}
void print(stack *ps){
int i;
while(!isEmpty(ps))
    printf("%d",pop(ps));
}

void main(){
int num;
stack s;
s.top=-1;
printf("Enter decimal number");
scanf("%d",&num);
while(num!=0){
    push(&s,num%2);
    num=num/2;
}
print(&s);
}
