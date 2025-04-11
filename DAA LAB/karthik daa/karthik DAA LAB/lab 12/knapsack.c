#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Item
{
int weight;
int value;
double ratio;
} Item;
typedef struct Node
{
int level;
int profit;
int weight;
double bound;
} Node;
int max(int a, int b)
{
return (a > b) ? a : b;
}
int compareItems(const void *a, const void *b)
{
double ratioA = (double)((Item *)a)->value / ((Item *)a)->weight;
double ratioB = (double)((Item *)b)->value / ((Item *)b)->weight;
if (ratioA < ratioB) return 1;
if (ratioA > ratioB) return -1;
return 0;
}
double calculateBound(Node u, Item items[], int n, int W)
{
if (u.weight >= W)
{
return 0;
}
double bound = u.profit;
int j = u.level + 1;
int totalWeight = u.weight;
while ((j < n) && (totalWeight + items[j].weight <= W))
{
totalWeight += items[j].weight;
bound += items[j].value;
j++;
}
if (j < n)
{
bound += (W - totalWeight) * items[j].ratio;
}
return bound;
}
int knapsackBranchAndBound(Item items[], int n, int W)
{
qsort(items, n, sizeof(Item), compareItems);
Node u, v;
int maxProfit = 0;
Node queue[1000]; // Simple queue, can be improved.
int front = 0, rear = 0;
u.level = -1;
u.profit = 0;
u.weight = 0;
u.bound = calculateBound(u, items, n, W);
queue[rear++] = u;
while (front != rear)
{
u = queue[front++];
if (u.bound > maxProfit)
{
v.level = u.level + 1;
v.weight = u.weight + items[v.level].weight;
v.profit = u.profit + items[v.level].value;
if (v.weight <= W && v.profit > maxProfit)
{
maxProfit = v.profit;
}
v.bound = calculateBound(v, items, n, W);
if (v.bound > maxProfit)
{
queue[rear++] = v;
}
v.weight = u.weight;
v.profit = u.profit;
v.bound = calculateBound(v, items, n, W);
if (v.bound > maxProfit)
{
queue[rear++] = v;
}
}
}
return maxProfit;
}
int main()
{
int i;
int n, W;
printf("Enter the number of items: ");
scanf("%d", &n);
Item *items = (Item *)malloc(n * sizeof(Item));
printf("Enter the weight and value of each item:\n");
for (i = 0; i < n; i++)
{
scanf("%d %d", &items[i].weight, &items[i].value);
items[i].ratio = (double)items[i].value / items[i].weight;
}
printf("Enter the knapsack capacity: ");
scanf("%d", &W);
int maxProfit = knapsackBranchAndBound(items, n, W);
printf("Maximum profit: %d\n", maxProfit);
free(items);
return 0;
}
