#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define V 5
typedef struct Edge
{
int src, dest, weight;
} Edge;

typedef struct Subset
{
int parent, rank;
} Subset;

int compareEdges(const void *a, const void *b)
{
return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int find(Subset subsets[], int i)
{
if (subsets[i].parent != i)
{
subsets[i].parent = find(subsets, subsets[i].parent);
}
return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y)
{
int xroot = find(subsets, x);
int yroot = find(subsets, y);
if (subsets[xroot].rank < subsets[yroot].rank)
{
subsets[xroot].parent = yroot;
} else if (subsets[xroot].rank > subsets[yroot].rank)
{
subsets[yroot].parent = xroot;
} else
{
subsets[yroot].parent = xroot;
subsets[xroot].rank++;
}
}

void kruskalMST(Edge edges[], int E)
{
int v;
Edge result[V];
int e = 0;
int i = 0;

qsort(edges, E, sizeof(edges[0]), compareEdges);

Subset *subsets = (Subset *)malloc(V * sizeof(Subset));

for (v = 0; v < V; v++)
{
subsets[v].parent = v;
subsets[v].rank = 0;
}

while (e < V - 1 && i < E)
{

Edge next_edge = edges[i++];
int x = find(subsets, next_edge.src);
int y = find(subsets, next_edge.dest);

{
result[e++] = next_edge;
Union(subsets, x, y);
}

}

printf("Edge \tWeight\n");
for (i = 0; i < e; i++)
{
printf("%d -- %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}
free(subsets);
}
int main()
{
int i,j,testE;
int E = 9;
Edge edges[] =
{
{0, 1, 2},
{0, 3, 6},
{1, 0, 2},
{1, 2, 3},
{1, 3, 8},
{1, 4, 5},
{2, 1, 3},
{2, 4, 7},
{3, 0, 6},
{3, 1, 8},
{3, 4, 9},
{4, 1, 5},
{4, 2, 7},
{4, 3, 9}
};
kruskalMST(edges, E);

clock_t start, end;
double cpu_time_used;
printf("\nTime Complexity Analysis:\n");
printf("Number of Edges\tTime (seconds)\n");
for (testE = 5; testE <= 50; testE += 5)
{
Edge *testEdges = (Edge *)malloc(testE * sizeof(Edge));
for (j = 0; j < testE; j++)
{
testEdges[j].src = rand() % V;
testEdges[j].dest = rand() % V;
testEdges[j].weight = rand() % 50 + 1;
}
start = clock();
kruskalMST(testEdges, testE);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("%d\t%f\n", testE, cpu_time_used);
free(testEdges);
}
return 0;
}
