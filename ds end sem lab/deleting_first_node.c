#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *link;
};


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

struct node* delete_first_node(struct node *head){
if(head==NULL){
    printf("Linked list is empty");
}
struct node *temp;
temp=head;
head=head->link;
free(temp);
temp=NULL;
return head;
}

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

head=delete_first_node(head);
print_data(head);
}
