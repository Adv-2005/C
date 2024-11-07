#include <stdio.h>


void selectionSort(int arr[], int n)
{
    int i, j, mini;

    for (i = 0; i < n-1; i++)
    {mini = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[mini])
            mini = j;


           if(mini != i){
             int temp = arr[mini];
             arr[mini] = arr[i];
              arr[i] = temp;
    }}
}


int main()
{
    int arr[100];
    int n,i;
    printf("Enter no of elements");
    scanf("%d", &n);
    printf("Enter array elements\n");
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    selectionSort(arr, n);
    printf("Sorted array: \n");
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
