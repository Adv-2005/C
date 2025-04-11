#include <stdio.h>
#include <stdlib.h>
#define MAX_CHARS 256

typedef struct Node
{
char data;
unsigned frequency;
struct Node *left, *right;
} Node;

typedef struct MinHeapNode
{
unsigned size;
unsigned capacity;
Node **array;
} MinHeapNode;
Node *newNode(char data, unsigned frequency)
{
Node *node = (Node *)malloc(sizeof(Node));
node->left = node->right = NULL;
node->data = data;
node->frequency = frequency;
return node;
}

MinHeapNode *createMinHeap(unsigned capacity)
{
MinHeapNode *minHeap = (MinHeapNode *)malloc(sizeof(MinHeapNode));
minHeap->size = 0;
minHeap->capacity = capacity;
minHeap->array = (Node **)malloc(minHeap->capacity * sizeof(Node *));
return minHeap;
}

void swapMinHeapNode(Node **a, Node **b)
{
Node *t = *a;
*a = *b;
*b = t;
}

void minHeapify(MinHeapNode *minHeap, int idx)
{
int smallest = idx;
int left = 2 * idx + 1;
int right = 2 * idx + 2;
if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
{
smallest = left;
}
if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
{
smallest = right;
}
if (smallest != idx)
{
swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
minHeapify(minHeap, smallest);
}
}

int isSizeOne(MinHeapNode *minHeap)
{
return (minHeap->size == 1);
}

Node *extractMin(MinHeapNode *minHeap)
{
Node *temp = minHeap->array[0];
minHeap->array[0] = minHeap->array[minHeap->size - 1];
--minHeap->size;
minHeapify(minHeap, 0);
return temp;
}

void insertMinHeap(MinHeapNode *minHeap, Node *minHeapNode)
{
++minHeap->size;
int i = minHeap->size - 1;
while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
minHeap->array[i] = minHeap->array[(i - 1) / 2];
i = (i - 1) / 2;
}
minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeapNode *minHeap)
{
int i;
int n = minHeap->size - 1;
for (i = (n - 1) / 2; i >= 0; --i)
{
minHeapify(minHeap, i);
}
}

Node *buildHuffmanTree(char data[], unsigned frequency[], int size)
{
Node *left, *right, *top;
int i;

MinHeapNode *minHeap = createMinHeap(size);
for (i = 0; i < size; ++i)
{
minHeap->array[i] = newNode(data[i], frequency[i]);
}
minHeap->size = size;
buildMinHeap(minHeap);
while (!isSizeOne(minHeap))
{
left = extractMin(minHeap);
right = extractMin(minHeap);
top = newNode('$', left->frequency + right->frequency);
top->left = left;
top->right = right;
insertMinHeap(minHeap, top);
}
return extractMin(minHeap);
}

void printCodes(Node *root, int arr[], int top)
{
int i;
if (root->left)
{
arr[top] = 0;
printCodes(root->left, arr, top + 1);
}
if (root->right)
{
arr[top] = 1;
printCodes(root->right, arr, top + 1);
}
if (!(root->left || root->right))
{
printf("%c: ", root->data);
for (i = 0; i < top; ++i)
{
printf("%d", arr[i]);
}
printf("\n");
}
}

int main()
{
char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
int freq[] = {5, 9, 12, 13, 16, 45};
int size = sizeof(arr) / sizeof(arr[0]);
Node *root = buildHuffmanTree(arr, freq, size);
int codes[MAX_CHARS], top = 0;
printCodes(root, codes, top);
return 0;
}
