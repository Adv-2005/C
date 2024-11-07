#include <stdio.h>
#include <stdlib.h>

int i,j,k;
void getMatrixElements(int** matrix, int row, int column) {
    printf("\nEnter elements:\n");
    for (i = 0; i < row; ++i) {
        for (j = 0; j < column; ++j) {
            printf("Enter a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}


void multiplyMatrices(int** first, int** second, int** result, int r1, int c1, int r2, int c2) {
    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j) {
            result[i][j] = 0;
            for (k = 0; k < c1; ++k) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}


void display(int** result, int row, int column) {
    printf("\nOutput Matrix:\n");
    for (i = 0; i < row; ++i) {
        for (j = 0; j < column; ++j) {
            printf("%d  ", result[i][j]);
            if (j == column - 1)
                printf("\n");
        }
    }
}

int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);


    int** first = (int**)malloc(r1 * sizeof(int*));
    int** second = (int**)malloc(r2 * sizeof(int*));
    int** result = (int**)malloc(r1 * sizeof(int*));

    for (i = 0; i < r1; ++i) {
        first[i] = (int*)malloc(c1 * sizeof(int));
        result[i] = (int*)malloc(c2 * sizeof(int));
    }

    for (i = 0; i < r2; ++i)
        second[i] = (int*)malloc(c2 * sizeof(int));


    getMatrixElements(first, r1, c1);
    getMatrixElements(second, r2, c2);


    multiplyMatrices(first, second, result, r1, c1, r2, c2);


    display(result, r1, c2);


    for (i = 0; i < r1; ++i) {
        free(first[i]);
        free(result[i]);
    }
    for (i = 0; i < r2; ++i)
        free(second[i]);

    free(first);
    free(second);
    free(result);

    return 0;
}
