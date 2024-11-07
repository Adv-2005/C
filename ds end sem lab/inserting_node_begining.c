#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *link;
};

struct node* insert_at_start(struct node *head, int data){

struct node *ptr;
ptr=(struct node*)malloc(sizeof(struct node));
ptr->data=data;
ptr->link=head;

head=ptr;
return head;
}

void print_data(struct node *head){
    if(head==NULL)
        printf("Empty linked list");
struct node *ptr;
ptr=head;
while(ptr!=NULL){
        printf("%d\t",ptr->data);
    ptr=ptr->link;
}
};

int main(){
struct node *head=malloc(sizeof(struct node));
head->data=30;
head->link=NULL;

struct node *current=malloc(sizeof(struct node));
current->data=98;
current->link=NULL;
head->link=current;

struct node *current1=malloc(sizeof(struct node));
current1->data=3;
current1->link=NULL;
head->link->link=current1;

head=insert_at_start(head,28);
print_data(head);
}
