#include<stdio.h>
int main(){
typedef struct{
int x;
int y;
char z;
float u;

}SAMPLE;

SAMPLE sam1;
SAMPLE *ptr;

ptr=&sam1;

printf("Enter int value ");
scanf("%d",&ptr->x);
printf("Integer value= %d",ptr->x);
}
