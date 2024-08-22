#include <stdio.h>
int search(int arr[], int a, int b, int element){
   if (b >= a){
      int middle = a + (b - a )/2;
      if (arr[middle] == element)
         return middle;
      if (arr[middle] > element)
         return search(arr, a, middle-1, element);
      return search(arr, middle+1, b, element);
   }
   return -1;
}
int main(){
   int arr[] = {1, 4, 7, 9, 16, 56, 70};
   int n=7,element;
   printf("Enter a number:\n");
   scanf("%d",&element);

   int pos = search(arr, 0, n-1, element);
   if(pos == -1 ) {
      printf("Element not found in the array ");
   }
   else {
      printf("Element found at Position : %d",pos+1);
   }
}
