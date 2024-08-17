#include <stdio.h>
int main(){
int *ptr,i=0;
int arr[100]={1,2,3,4,5,6};
ptr=arr;
while(i<6){
    printf("%d,",*ptr);
    ptr++;
    i++;
}

//printf("Array of element : %d", *ptr);
}
