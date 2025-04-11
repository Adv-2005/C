#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define V 6 // Number of vertices in the graph
// Function to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int sptSet[])
{
int v;
int min = INT_MAX, min_index;
for (v = 0; v < V; v++)
{
if (sptSet[v] == 0 && dist[v] <= min)
{
min = dist[v];
min_index = v;
}
}
return min_index;
}
// Function to print the constructed distance array
void printSolution(int dist[], int src)
{
int i;
printf("Vertex \t Distance from Vertex %d\n", src);
for (i = 0; i < V; i++)
{
printf("%d \t\t %d\n", i, dist[i]);
}
}
// Function that implements Dijkstra's single source shortest path algorithm for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
int i, v, count;
int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i
int sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized
// Initialize all distances as INFINITE and sptSet[] as false
for (i = 0; i < V; i++)
{
dist[i] = INT_MAX;
sptSet[i] = 0;
}
// Distance of source vertex from itself is always 0
dist[src] = 0;
// Find shortest path for all vertices
for ( count = 0; count < V - 1; count++)
{
// Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in first iteration.
int u = minDistance(dist, sptSet);
// Mark the picked vertex as processed
sptSet[u] = 1;
// Update dist value of the adjacent vertices of the picked vertex.
for (v = 0; v < V; v++)
{
// Update dist[v] only if is not in sptSet, there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of dist[v]
if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
dist[v] = dist[u] + graph[u][v];
}
}
}
// print the constructed distance array
printSolution(dist, src);
}
int main()
{
int i,j,testV;
int graph[V][V] =
{
{0, 4, 0, 0, 0, 0},
{4, 0, 8, 0, 0, 0},
{0, 8, 0, 7, 0, 4},
{0, 0, 7, 0, 9, 14},
{0, 0, 0, 9, 0, 10},
{0, 0, 4, 14, 10, 0}
};
int src = 0; // Source vertex
dijkstra(graph, src);
// Time complexity analysis
clock_t start, end;
double cpu_time_used;
printf("\nTime Complexity Analysis:\n");
printf("Number of Vertices\tTime (seconds)\n");
for (testV = 2; testV <= 10; testV++)
{
int **testGraph = (int **)malloc(testV * sizeof(int *));
for (i = 0; i < testV; i++)
{
testGraph[i] = (int *)malloc(testV * sizeof(int));
for (j = 0; j < testV; j++)
{
if (i == j)
{
testGraph[i][j] = 0;
} else
{
testGraph[i][j] = (rand() % 2 == 0) ? 0 : (rand() % 10 + 1); // Random weights 1-10 or 0 for no edge
}
}
}
start = clock();
dijkstra(testGraph, 0); // Always start from vertex 0
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("%d\t%f\n", testV, cpu_time_used);
// Free allocated memory
for (i = 0; i < testV; i++)
{
free(testGraph[i]);
}
free(testGraph);
}
return 0;
}
