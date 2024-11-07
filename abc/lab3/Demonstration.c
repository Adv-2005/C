#include <stdio.h>


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* getNumber() {
    static int num = 42;
    return &num;
}

int main() {
    int x = 10, y = 20;
    int var = 789;
    int* ptr1;
    int** ptr2;


    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);
    ptr1 = getNumber();
    printf("Value retrieved using pointer: %d\n", *ptr1);


    ptr2 = &ptr1;
    printf("Value using double pointer: %d\n", **ptr2);


}
