#include <stdio.h>

#define MAX_VERTICES 5

void displayAdjacencyList(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int i;int j;
    for ( i = 0; i < numVertices; i++) {
        printf("Adjacency list of vertex %d\n head ", i);
        for ( j = 0; j < numVertices; j++) {
            if (graph[i][j] == 1) {
                printf("-> %d", j);
            }
        }
        printf("\n");
    }
}

void displayAdjacencyMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Adjacency Matrix:\n");int i; int j;
    for ( i = 0; i < numVertices; i++) {
        for ( j = 0; j < numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices = MAX_VERTICES;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    graph[0][1] = 1;
    graph[0][4] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][1] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;
    graph[4][0] = 1;
    graph[4][1] = 1;
    graph[4][3] = 1;

    displayAdjacencyList(graph, numVertices);
    displayAdjacencyMatrix(graph, numVertices);

    return 0;
}
