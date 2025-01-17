#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int i,j;
void bubble_sort(int arr[], int n) {
    for ( i = 0; i < n-1; i++) {
        for ( j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


double measure_time(int arr[], int n) {
    clock_t start_time, end_time;
    start_time = clock();
    bubble_sort(arr, n);
    end_time = clock();
    return ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}

int main() {
    int sizes[] = {100, 200, 300, 400, 500};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    double *best_case_times = (double *)malloc(num_sizes * sizeof(double));
    double *worst_case_times = (double *)malloc(num_sizes * sizeof(double));

    for ( i = 0; i < num_sizes; i++) {
        int size = sizes[i];


        int *arr_best_case = (int *)malloc(size * sizeof(int));
        for ( j = 0; j < size; j++) {
            arr_best_case[j] = j;
        }


        int *arr_worst_case = (int *)malloc(size * sizeof(int));
        for ( j = 0; j < size; j++) {
            arr_worst_case[j] = size - j;
        }

        best_case_times[i] = measure_time(arr_best_case, size);
        worst_case_times[i] = measure_time(arr_worst_case, size);

        free(arr_best_case);
        free(arr_worst_case);
    }

    printf("Array Size\tBest Case Time\tWorst Case Time\n");
    for ( i = 0; i < num_sizes; i++) {
        printf("%d\t\t%f\t%f\n", sizes[i], best_case_times[i], worst_case_times[i]);
    }

    free(best_case_times);
    free(worst_case_times);

    return 0;
}
