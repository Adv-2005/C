
#include<stdio.h>
int main(){
int arr[100],n,i;

printf("Enter the numeber of elements in array");
scanf("%d",&n);
printf("Enter array elements\n");
for(i=0; i<n; i++){
    scanf("&d",&arr[i]);
}
printf("Your array:\n");
for(i=0; i<n;i++){
    printf("%d",arr[i]);
}
return 0;
}
