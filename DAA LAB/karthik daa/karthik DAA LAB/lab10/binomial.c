#include <stdio.h>
#include <stdlib.h>
int binomialCoeff(int n, int k)
{
if (k > n)
{
return 0;
}
if (k == 0 || k == n)
{
return 1;
}
int **C = (int **)malloc((n + 1) * sizeof(int *));
if (C == NULL)
{
fprintf(stderr, "Memory allocation failed\n");
exit(1);
}
int i,j;
for (i = 0; i <= n; i++)
{
C[i] = (int *)malloc((k + 1) * sizeof(int));
if (C[i] == NULL)
{
fprintf(stderr, "Memory allocation failed\n");
exit(1);
}
}
for (i = 0; i <= n; i++)
{
for (j = 0; j <= (i < k ? i : k); j++)
{
if (j == 0 || j == i)
{
C[i][j] = 1;
}
else
{
C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
}
}
}
int result = C[n][k];
// Free allocated memory
for (i = 0; i <= n; i++)
{
free(C[i]);
}
free(C);
return result;
}
int main()
{
int n, k;
printf("Enter the value of n: ");
scanf("%d", &n);
printf("Enter the value of k: ");
scanf("%d", &k);
int coeff = binomialCoeff(n, k);
printf("Binomial Coefficient C(%d, %d) = %d\n", n, k, coeff);
return 0;
}
