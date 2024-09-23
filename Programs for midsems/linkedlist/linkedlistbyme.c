#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node *link;
}list;

void insert_end(list *head,int data){
list *ptr =(list*)malloc(sizeof(list));
list *p=head;
ptr->data=data;
while(p->link!=NULL){
    p=p->link;
}
ptr->link=NULL;
p->link=ptr;
}

void print(list *head){
    list *p=head;

    while(p!=NULL){
        printf("%d ",p->data);
        p=p->link;
    }
}
void count(list *head){
list *p=head;
int i=0;
while(p!=NULL){
    p=p->link;
    i++;
}
printf("Number of nodes =%d",i);

}
void insert_node(list *n,int data){
    list *ptr;
    ptr=(list *)malloc(sizeof(list));
    ptr->data=data;
    int temp=ptr->link;
    n->link=ptr->link;
    ptr->link=temp;

}
void main(){
    list *head;
    list *second;
    second=(list *)malloc(sizeof(list));
    head=(list *)malloc(sizeof(list));

    head->data=3;
    head->link=second;

    second->data=4;
    second->link=NULL;

    insert_end(head,2);
    insert_node(head,5);
    print(head);
    count(head);
}
