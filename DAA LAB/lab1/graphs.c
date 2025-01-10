#include <stdio.h>
#include <stdlib.h>

int i,v;
struct ListNode {
    int dest;
    struct ListNode* next;
};

struct List {
    struct ListNode* head;
};


struct Graph {
    int vertices;
    struct List* array;
};


struct ListNode* createListNode(int dest) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct List*)malloc(vertices * sizeof(struct List));
    for ( i = 0; i < vertices; ++i)
        graph->array[i].head = NULL;
    return graph;
}


void addEdge(struct Graph* graph, int src, int dest) {
    struct ListNode* newNode = createListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(struct Graph* graph) {
    for ( v = 0; v < graph->vertices; ++v) {
        struct ListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}

