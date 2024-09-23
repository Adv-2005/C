#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_midsem_char.h"

int isop(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 1;
    else
        return 0;
}

int priority(char x){
    switch(x){
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void conv_to_postfix(char* a, char* postfix){
    stack2 s;
    init(&s);
    int k=0;
    for(int i=0; i<strlen(a);i++){
        if (a[i] == '(')
            push(&s, a[i]);
        else if (a[i] == ')') {
            while (!isemp(&s) && s.item[s.top] != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); //to remove '('
        }
        else if (isop(a[i])) {
            while (!isemp(&s) && priority(s.item[s.top]) >= priority(a[i])) {
                postfix[k++] = pop(&s);
            }
            push(&s, a[i]);
        }
        else
            postfix[k++]=a[i];
    }
     while (!isemp(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';
}

void reverse(char *a){
    stack2 s;
    init(&s);
    for(int i=0; i<strlen(a);i++){
        if(a[i]=='(')
            push(&s, ')');
        else if(a[i]==')')
            push(&s, '(');
        else{
            push(&s, a[i]);
        }
    }
    for(int i=0; i<strlen(a);i++){
        a[i]=pop(&s);
    }
}
void main(){
    char infix[100],postfix[100];
    printf("enter infix expression : ");
    gets(infix);
    reverse(infix);
    puts(infix);
    conv_to_postfix(infix,postfix);
    printf("\n%s\n", postfix);
    reverse(postfix);
    puts(postfix);
}

