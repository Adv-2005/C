#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *link;
};
void insert_at_pos(struct node *head, int data,int pos){
struct node *ptr,*ptr2;
ptr2=malloc(sizeof(struct node));
ptr2->data=data;
ptr2->link=NULL;
ptr=head;
pos--;
while(pos!=1){
    ptr=ptr->link;
    pos--;
}
ptr2->link=ptr->link;
ptr->link=ptr2;
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

insert_at_pos(head,28,2);
print_data(head);

}
