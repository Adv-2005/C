
#include <stdio.h>
int lsearch(int arr[], int size, int element, int index){
if(arr[index]==element){
    return index;
}
    return lsearch( arr,  size, element, index+1);

}

int main(){
int a[5]={1,2,3,4,5};
int element=4;
int index=lsearch(a,sizeof(a)/sizeof(int),element,0);
printf("Element is present at index %d",index);
}
