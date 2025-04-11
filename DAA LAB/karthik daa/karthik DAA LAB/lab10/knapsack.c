#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
return (a > b) ? a : b;
}
int knapsack(int W, int wt[], int val[], int n) {
int i, w;
int K[n + 1][W + 1];
// Build table K[][] in bottom up manner
for (i = 0; i <= n; i++)
{
for (w = 0; w <= W; w++)
{
if (i == 0 || w == 0)
K[i][w] = 0;
else if (wt[i - 1] <= w)
K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
else
K[i][w] = K[i - 1][w];
}
}
return K[n][W];
}
int main()
{
int i,n, W;
printf("Enter the number of items: ");
scanf("%d", &n);
int val[n], wt[n];
printf("Enter the values of the items:\n");
for (i = 0; i < n; i++)
{
scanf("%d", &val[i]);
}
printf("Enter the weights of the items:\n");
for (i = 0; i < n; i++)
{
scanf("%d", &wt[i]);
}
printf("Enter the capacity of the knapsack: ");
scanf("%d", &W);
printf("Maximum value that can be obtained: %d\n", knapsack(W, wt, val, n));
return 0;
}
