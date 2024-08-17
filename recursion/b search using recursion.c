#include<stdio.h>
int bsearch(int arr[], int low, int high,int element){
int mid= (low+high)/2;
if(arr[mid]==element){
    return mid;
}
else if(arr[mid]>element){
return bsearch(arr,low,mid-1,element);
}
else if(arr[mid]<element){
return bsearch(arr,mid+1,high,element);}
}
int main(){
    int a[]={1,2,3,4,5};
    int element=4;
    int low=0;
    int size=sizeof(a)/sizeof(int);
    int high=size-1;
    printf("Element is present at index %d",bsearch(a,low,high,4));

}
