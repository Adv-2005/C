#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#include<string.h>
typedef struct{
char word[MAX];
int top;
}stack;
void push(stack *ps , char value){
    if(isFull(ps)){
        printf("Stack Overflow");
    }
    else{
        ps->word[++(ps->top)]=value;
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

char pop(stack *ps){
if(isEmpty(ps)){
    printf("Stack underflow!");
}
else{
    return(ps->word[ps->top--]);
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
    int i;
stack s;
s.top=-1;
char word[MAX];
printf("Enter Word\n");
gets(word);
while(word[i]!='\0'){
    push(&s,word[i]);
    i++;
}
int check=0;
for(i=0;i<(s.top+1)/2;i++){
    if(pop(&s)!=word[i])
        check=1;
}
if(check==1)
    printf("Not a Palindrome");
else{
    printf("Palindrome");
}
}
