#include <stdio.h>
void main(){
int i,j,arr[10],n;
printf("Enter no of elements:\n");
scanf("%d", &n);
printf("Enter elements");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
for (i=0;i<n-1;i++){
for(j=0;j<n-i-1;j++){
if(arr[j]>arr[j+1]){
int temp;
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}}
printf("Array after sorted");
for(i=0;i<n;i++)
printf("%d,",arr[i]);
}
