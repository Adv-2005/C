#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *link;
};

struct node* del_list(struct node *head){
    struct node *temp=head;
while(temp!=NULL){
        temp=temp->link;
        free(head);
        head=temp;

    }
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

head=del_list(head);
if(head==NULL){
    printf("Deleted");
}
print_data(head);
}

