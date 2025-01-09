
#include<stdio.h>
int main(){
typedef struct{
char name[20];
char id[10];
int gpa;
}STUDENT;
STUDENT s1;

scanf("%d",&s1.gpa);
printf("Gpa of s1 is %d",s1.gpa);
}
