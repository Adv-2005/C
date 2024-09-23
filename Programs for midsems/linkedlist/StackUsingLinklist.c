#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;

    int nodes;
}Stack;

Stack *stackHead = NULL;


void push(Stack *s,int ele){
    if(s->nodes == 0){
        Stack *head = (Stack *)malloc(sizeof(Stack));

        head->data = ele;
        head->next = NULL;

        stackHead = head;
        s->nodes++;
    }else{

        Stack *ptr = (Stack *)malloc(sizeof(Stack));
        ptr->data = ele;
        Stack *p = stackHead;

        while(p->next != NULL){
            p=p->next;
        }

        ptr->next = NULL;
        p->next = ptr;

    }
}

void pop(Stack *s){
    if(s->nodes == -1){
        printf("Stack Underflow!\n");
    }else{
        Stack *p = stackHead->next;
        Stack *q = stackHead;
        while(p->next != NULL){
            p=p->next;
            q=q->next;
        }

        q->next = NULL;
        free(p);

        s->nodes--;

    }
}

void print(Stack *s){
    Stack *p = stackHead;

    while(p!=NULL){
        printf("%d, ", p->data);
        p=p->next;
    }

    printf("\n");
}

int main(){
    Stack s;
    s.nodes = 0;

    push(&s,25);
    push(&s,26);
    push(&s,27);
    


    print(&s);
}