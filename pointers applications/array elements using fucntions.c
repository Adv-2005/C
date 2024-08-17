#include<stdio.h>
int main(){
int arr[5]={1,2,3,4,5},i;
for(i=0;i<5;i++){

    display(&arr[i]);
}
}
void display(int *ptr){
printf("%d",*ptr);
}
