#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to swap two integers
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
// Partition function
int partition(int arr[], int low, int high)
{
int pivot = arr[high]; // Choose the last element as the pivot
int i = (low - 1); // Index of smaller element
int j;
for (j = low; j <= high - 1; j++)
{
if (arr[j] < pivot)
{
i++;
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}
// Quick sort function
void quickSort(int arr[], int low, int high)
{
if (low < high)
{
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1); // Sort left partition
quickSort(arr, pi + 1, high); // Sort right partition
}
}
// Function to generate random integers
void generateRandomArray(int arr[], int n)
{int i;
for (i = 0; i < n; i++)
{
arr[i] = rand() % 1000; // Generates random numbers between 0 and 999
}
}
int main()
{
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
int *arr = (int *)malloc(n * sizeof(int)); //Dynamically allocate memory
if (arr == NULL)
{
perror("Memory allocation failed");
return 1;
}
// Generate random array for testing
generateRandomArray(arr, n);
clock_t start, end;
double cpu_time_used;
start = clock();
quickSort(arr, 0, n - 1);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);
/* (Optional) Print the sorted array for verification
printf("Sorted array: \n");
for (int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
*/
free(arr); // Free the dynamically allocated memory
return 0;
}
