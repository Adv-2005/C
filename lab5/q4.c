#include <stdio.h>
#include <stdlib.h>

int i;
void deleteElements(int arr[], int n, int k) {
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;
    int count = 0;

    for ( i = 0; i < n; i++) {
        while (top != -1 && stack[top] < arr[i] && count < k) {
            top--;
            count++;
        }
        stack[++top] = arr[i];
    }

    for ( i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    free(stack);
}

int main() {
    int arr[] = {20, 10, 25, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printf("Original array: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Array after deleting %d elements: ", k);
    deleteElements(arr, n, k);

    return 0;
}

