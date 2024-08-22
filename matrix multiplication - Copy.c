#include<stdio.h>
int main() {
int a[5][5], b[5][5], c[5][5], n, i, j, k;

printf("Enter the value of N (N <= 5): ");
scanf("%d", & n);
printf("Enter the elements of Matrix-1: \n");

for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
scanf("%d", & a[i][j]);
}
}

printf("Enter the elements of Matrix-2: \n");

for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
scanf("%d", & b[i][j]);
}
}

for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
c[i][j] = 0;
for (k = 0; k < n; k++) {
c[i][j] += a[i][k] * b[i][j];
}
}
}

printf("The product of the two matrices is: \n");
for (i = 0; i < n; i++) {
for (j = 0; j< n; j++) {
printf("%d\t", c[i][j]);
}
printf("\n");
}
return 0;
}
