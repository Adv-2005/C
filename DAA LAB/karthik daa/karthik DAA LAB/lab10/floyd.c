#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define INF INT_MAX / 2 // To avoid overflow during addition
void floydWarshall(int **graph, int n)
{
int i,j,k;
for (k = 0; k < n; k++)
{
for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
if (graph[i][k] != INF && graph[k][j] != INF &&
graph[i][k] + graph[k][j] < graph[i][j]) {
graph[i][j] = graph[i][k] + graph[k][j];
}
}
}
}
}
void printSolution(int **graph, int n)
{
int i,j;
printf("Shortest distances between every pair of vertices:\n");
for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
if (graph[i][j] == INF)
{
printf("INF\t");
} else
{
printf("%d\t", graph[i][j]);
}
}
printf("\n");
}
}
int main()
{
int i,j,size;
int n;
printf("Enter the number of vertices: ");
scanf("%d", &n);
int **graph = (int **)malloc(n * sizeof(int *));
for (i = 0; i < n; i++)
{
graph[i] = (int *)malloc(n * sizeof(int));
}
printf("Enter the adjacency matrix (INF(-1) for no edge):\n");
for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
scanf("%d", &graph[i][j]);
if (graph[i][j] == -1)
{ // Use -1 to represent infinity in input
graph[i][j] = INF;
}
}
}
clock_t start, end;
double cpu_time_used;
start = clock();
floydWarshall(graph, n);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printSolution(graph, n);
printf("\nTime taken: %f seconds\n", cpu_time_used);
// Experimental Results for Order of Growth
printf("\nExperimental Results for Order of Growth:\n");
printf("N\tTime (seconds)\n");
for (size = 2; size <= 100; size += 5)
{
int **testGraph = (int **)malloc(size * sizeof(int *));
for (i = 0; i < size; i++)
{
testGraph[i] = (int *)malloc(size * sizeof(int));
for (j = 0; j < size; j++)
{
if (i == j)
{
testGraph[i][j] = 0;
} else
{
testGraph[i][j] = (rand() % 2 == 0) ? INF : (rand() % 10 + 1); // Random weights 1-10 or INF
}
}
}
start = clock();
floydWarshall(testGraph, size);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("%d\t%f\n", size, cpu_time_used);
// Free allocated memory
for (i = 0; i < size; i++)
{
free(testGraph[i]);
}
free(testGraph);
}
// Free allocated memory for original graph
for (i = 0; i < n; i++)
{
free(graph[i]);
}
free(graph);
return 0;
}

