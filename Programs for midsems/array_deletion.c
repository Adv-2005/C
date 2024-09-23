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
    for (int i = 0; i <= ps->top; i++) {
        printf("%d ", ps->bin[i]);
    }
    printf("\n");
}
void main(){
    int i,n,k,c=0;
    printf("Enter number of elements\n");
scanf("%d",&n);
    int arr[n];
    stack s;
    s.top=-1;

printf("Enter elements\n");
for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
printf("Enter k\n");
scanf("%d",&k);
for(i=0;i<n;i++){
    while(!isEmpty(&s)&& c<k && s.bin[s.top]<arr[i]){
        pop(&s);
        c++;
    }
    push(&s,arr[i]);
}
print(&s);
}
