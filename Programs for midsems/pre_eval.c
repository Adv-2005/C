#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#include<string.h>
typedef struct{
char eval[MAX];
int top;
}stack;
void push(stack *ps , char value){
    if(isFull(ps)){
        printf("Stack Overflow");
    }
    else{
        ps->eval[++(ps->top)]=value;
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
    return(ps->eval[ps->top--]);
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
    char a,b;
    stack s;
    s.top=-1;
    char post[MAX];
    printf("Enter prefix Expression");
    gets(post);
    for(i=strlen(post)-1;i>=0;i--){
        if(post[i]>='0'&&post[i]<='9')
            push(&s,post[i]-'0');
            else{
                a=pop(&s);
                b=pop(&s);
                switch(post[i]){
            case '+' :
                push(&s,a+b);break;
            case '-' :
                push(&s,a-b);break;
            case '*':
                push(&s,a*b);break;
            case '/':
                push(&s,a/b);break;
            case '^':
                push(&s,pow(a,b));break;
                }
            }


    }
    printf("%d",pop(&s));
}

