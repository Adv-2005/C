#include <stdio.h>
#include <stdlib.h>
// Function to swap two integers
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
// Function to heapify a subtree rooted at index i (bottom-up)
void heapify(int arr[], int n, int i)
{
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && arr[left] > arr[largest])
largest = left;
if (right < n && arr[right] > arr[largest])
largest = right;
if (largest != i) {
swap(&arr[i], &arr[largest]);
heapify(arr, n, largest);
}
}
// Function to build a max-heap using bottom-up approach
void buildMaxHeap(int arr[], int n)
{
int i;
for (i = n / 2 - 1; i >= 0; i--)
heapify(arr, n, i);
}
// Function to print an array
void printArray(int arr[], int n)
{
int i,j;
for (i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
}
int main()
{
int keys[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7}; // Example list of keys
int n = sizeof(keys) / sizeof(keys[0]);
printf("Original array: ");
printArray(keys, n);
buildMaxHeap(keys, n);
printf("Max-heap: ");
printArray(keys, n);
//Example with a different set of numbers
int keys2[] = {12, 11, 13, 5, 6, 7};
int n2 = sizeof(keys2) / sizeof(keys2[0]);
printf("\n Original array 2: ");
printArray(keys2, n2);
buildMaxHeap(keys2, n2);
printf("Max-heap 2: ");
printArray(keys2, n2);
return 0;
}
