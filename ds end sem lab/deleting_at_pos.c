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

void delete_at_pos(struct node* head,int pos){
struct node *current=head;
struct node *previous=head;
if(head==NULL){
    printf("List is empty");
}
else if(pos==1){
    head=current->link;
    free(current);
    current=NULL;
}
else{

while(pos!=1){
    previous=current;
    current=current->link;
    pos--;
}
previous->link=current->link;
free(current);
current=NULL;
}
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

delete_at_pos(head,2);
print_data(head);

}
