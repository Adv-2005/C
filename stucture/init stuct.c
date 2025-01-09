#include<stdio.h>
typedef struct{
char id[10];
char name[10];
int gpa;
}STUDENT;
int main(){
STUDENT s1={"ADV","ADITYA",8};
STUDENT s2;
s2=s1;
printf("%d",s2.gpa);


}
