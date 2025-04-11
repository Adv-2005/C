#include <stdio.h>
#include <stdlib.h>
void comparisonCountingSort(int arr[], int n)
{
int* count = (int*)malloc(n * sizeof(int));
int* sortedArr = (int*)malloc(n * sizeof(int));
int i,j;
// Initialize count array to 0
for (i = 0; i < n; i++)
{
count[i] = 0;
}
// Count comparisons
for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
if (arr[i] > arr[j])
{
count[i]++;
}
}
}
// Place elements in sorted array
for ( i = 0; i < n; i++)
{
sortedArr[count[i]] = arr[i];
}
// Copy sorted array back to original array
for (i = 0; i < n; i++)
{
arr[i] = sortedArr[i];
}
// Free allocated memory
free(count);
free(sortedArr);
}
int main()
{
int i;
int arr[] = {4, 2, 7, 1, 9, 5};
int n = sizeof(arr) / sizeof(arr[0]);
printf("Original array: ");
for (i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
printf("\n");
comparisonCountingSort(arr, n);
printf("Sorted array: ");
for (i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
printf("\n");
return 0;
}
