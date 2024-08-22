
#include <stdio.h>

void SelectionSort(int arr[], int i, int j, int len, int flag)
{
    if (i < len - 1) {
        if (flag)
            j = i + 1;

        if (j < len) {
            if (arr[i] > arr[j])
            {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
            SelectionSort(arr, i, j + 1, len, 0);
        }
        SelectionSort(arr, i + 1, 0, len, 1);
    }
}

int main()
{
    int arr[100];
    int i,n;
    printf("Enter no of elements\n");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }



    SelectionSort(arr, 0, 0, 5, 1);

    printf("\nArray after sorting: \n");
    for (i = 0; i < 5; i++)
        printf("%d  ", arr[i]);

    printf("\n");

    return 0;
}
