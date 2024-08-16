#include<stdio.h>
int main(){
int arr[100],n,i;
printf("Enter the number of elements for array\n");
scanf("%d",&n);
printf("Enter array elements\n");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
printf("Your array elements are:\n");
for(i=0;i<n;i++){
printf("%d,",arr[i]);
}
}
