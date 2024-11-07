#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *link;
};

void delete_last_node(struct node *head){
if(head==NULL)
    printf("List is empty");
else if(head->link==NULL){
    free(head);
    head=NULL;
}
else{
    struct node *temp=head;
    struct node*temp2=head;
    while(temp->link!=NULL){
        temp2=temp;
        temp=temp->link;
    }
    temp2->link=NULL;
    free(temp);
    temp=NULL;

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

delete_last_node(head);
print_data(head);
}
