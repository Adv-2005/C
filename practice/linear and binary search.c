
#include<stdio.h>
int linearsearch(int arr[],int size,int element){
    int i=0;
    for(i=0;i<size;i++){
        if(arr[i]== element){
            return i;
        }

    }
    return -1;
}

int binarysearch(int arr[],int size,int element){
int i=0;
int low=0;
int high=size-1;
int mid;

while(low<=high){

 mid=(low+high)/2;
    if(arr[mid]==element){
        return mid;
    }
    else if(arr[mid]<element){
        low=mid+1;
    }
    else if(arr[mid]>element){
        high=mid-1;
    }
}
return -1;
}
int main(){

    int a[8]={1,2,3,4,5,6,7,8};
    int size= sizeof(a)/sizeof(int);
    int element=4;
    //printf("Element is present at index %d",linearsearch(a, size, element));
    printf("Element is present at index %d",binarysearch(a,size,element));

}
