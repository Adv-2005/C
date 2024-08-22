#include <stdio.h>
#include <stdlib.h>

int findSmallest(int* arr, int size) {
    int* ptr = arr;
    int smallest = *ptr;
int i;
    for (i = 1; i < size; i++) {
        if (*(ptr + i) < smallest) {
            smallest = *(ptr + i);
        }
    }

    return smallest;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int* arr = (int*)malloc(size * sizeof(int));
    printf("Enter %d integer numbers:\n", size);
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int smallestElement = findSmallest(arr, size);
    printf("Smallest Element in the Array: %d\n", smallestElement);
    free(arr);

}

