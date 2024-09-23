#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node* next;
}list;


void listTraversal(list *ele) {
    while (ele != NULL) {
        printf("Element: %d\n", ele->data);
        ele = ele->next;
    }
}

list *insertAtFirst(list *head, int data) {
    list *ptr = (list *)malloc(sizeof(list));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

void insertAtBetween(list *head, int data, int index) {
    list *ptr = (list *)malloc(sizeof(list));
    list *p = head;
    int i = 0;

    while (i != index - 1) {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
}

void insertAtEnd(list *head, int data) {
    list *ptr = (list *)malloc(sizeof(list));
    list *p = head;
    ptr->data = data;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
}

void insertAtNode(list *node, int data) {
    list *ptr = (list *)malloc(sizeof(list));
    ptr->data = data;

    ptr->next = node->next;
    node->next = ptr;
}

list *deleteHead(list *head) {
    //list *ptr = (list *)malloc(sizeof(list));
    list *ptr = head;
    head = head->next;
    free(ptr);
    return head;

}

int countNodes(list *head){
    list *p = head;
    int i = 0;
    while(p!=NULL){
        p=p->next;
        i++;
    }

    return i;
}

void deleteAtIndex(list *head,int index){

    list *p = head;
    list *q = head->next;

    int i = 0;
    while(i != index-1){

        p=p->next;
        q=q->next;

        i++;

    }

    p->next = q->next;
    free(q);

}

void deleteAtValue(list *head, int val){
    list *p = head;
    list *q = head->next;

    while(q->data != val){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);


}

int main() {
    list *head;
    list *second;
    list *third;
    list *fourth;

    head = (list *)malloc(sizeof(list));
    second = (list *)malloc(sizeof(list));
    third = (list *)malloc(sizeof(list));
    fourth = (list *)malloc(sizeof(list));

    head->data = 2;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 8;
    fourth->next = NULL;

    insertAtEnd(head, 69);
    insertAtNode(second, 55);
    head = insertAtFirst(head, 99);
    insertAtBetween(head, 78, 4);
    head = deleteHead(head);
    deleteAtIndex(head,2);
    deleteAtValue(head,69);
    listTraversal(head);
    printf("Nodes : %d",countNodes(head));



    return 0;
}
