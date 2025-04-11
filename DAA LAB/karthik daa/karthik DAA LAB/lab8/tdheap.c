#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// Function to swap two integers
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i)
{
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && arr[left] > arr[largest])
largest = left;
if (right < n && arr[right] > arr[largest])
largest = right;
if (largest != i)
{
swap(&arr[i], &arr[largest]);
heapify(arr, n, largest);
}
}
// Function to build a heap using top-down approach (insertion)
void buildHeapTopDown(int arr[], int n)
{
int i;
for (i = 1; i < n; i++)
{
int j = i;
while (j > 0 && arr[j] > arr[(j - 1) / 2])
{
swap(&arr[j], &arr[(j - 1) / 2]);
j = (j - 1) / 2;
}
}
}
// Function to print an array
void printArray(int arr[], int n)
{
int i;
for (i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
}
// Function to measure the time taken for heap construction
double measureTime(int arr[], int n)
{
clock_t start, end;
double cpu_time_used;
start = clock();
buildHeapTopDown(arr, n);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
return cpu_time_used;
}
int main()
{
int i,j;
int sizes[] = {1000000, 2000000, 3000000, 4000000, 5000000};
int numSizes = sizeof(sizes) / sizeof(sizes[0]);
printf("Array Size\tTime (seconds)\n");
for (i = 0; i < numSizes; i++)
{
int n = sizes[i];
int *arr = (int *)malloc(n * sizeof(int));
// Generate random array
srand(time(NULL) + i); // Seed with different values to get different random sequences
for (j = 0; j < n; j++)
{
arr[j] = rand() % 1000; // Random numbers between 0 and 999
}
double timeTaken = measureTime(arr, n);
printf("%d\t\t%lf\n", n, timeTaken);
free(arr);
}
return 0;
}
