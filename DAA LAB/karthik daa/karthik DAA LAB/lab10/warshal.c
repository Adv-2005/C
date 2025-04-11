#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void warshall(int **graph, int n)
{
int i,j,k;
for (k = 0; k < n; k++)
{
for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
}
}
}
}
void printGraph(int **graph, int n)
{
int i,j;
for ( i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
printf("%d ", graph[i][j]);
}
printf("\n");
}
}
int main()
{
int n;
int i,j,size;
printf("Enter the number of vertices: ");
scanf("%d", &n);
int **graph = (int **)malloc(n * sizeof(int *));
for ( i = 0; i < n; i++)
{
graph[i] = (int *)malloc(n * sizeof(int));
}
printf("Enter the adjacency matrix:\n");
for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
{
scanf("%d", &graph[i][j]);
}
}
clock_t start, end;
double cpu_time_used;
start = clock();
warshall(graph, n);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("\nTransitive Closure:\n");
printGraph(graph, n);
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
for(j=0; j<size; j++)
{
testGraph[i][j] = rand() % 2;
}
}
start = clock();
warshall(testGraph, size);
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
