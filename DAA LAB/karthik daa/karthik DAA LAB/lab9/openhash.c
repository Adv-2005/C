#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
typedef struct Node
{
int key;
struct Node* next;
} Node;
Node* hashTable[TABLE_SIZE];
int hash(int key)
{
return key % TABLE_SIZE;
}
void insert(int key)
{
int index = hash(key);
Node* newNode = (Node*)malloc(sizeof(Node));
if (newNode == NULL)
{
fprintf(stderr, "Memory allocation failed\n");
exit(1);
}
newNode->key = key;
newNode->next = hashTable[index];
hashTable[index] = newNode;
}
int search(int key, int* comparisons, int successful)
{
int index = hash(key);
Node* current = hashTable[index];
*comparisons = 0;
while (current != NULL)
{
(*comparisons)++;
if (current->key == key)
{
return 1; // Found
}
current = current->next;
}
if (successful == 0)
{
(*comparisons)++; // Count the last comparison that led to NULL
}
return 0; // Not found
}
void display()
{
int i;
for (i = 0; i < TABLE_SIZE; i++)
{
printf("Hash Table [%d]: ", i);
Node* current = hashTable[i];
while (current != NULL)
{
printf("%d -> ", current->key);
current = current->next;
}
printf("NULL\n");
}
}
int main()
{
int keys[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16};
int numKeys = sizeof(keys) / sizeof(keys[0]);
int comparisons, found;
int i;
// Initialize hash table
for (i = 0; i < TABLE_SIZE; i++)
{
hashTable[i] = NULL;
}
// Insert keys into hash table
for (i = 0; i < numKeys; i++)
{
insert(keys[i]);
}
display();
// Successful search
int searchKey = 13;
found = search(searchKey, &comparisons, 1);
if (found)
{
printf("Key %d found (successful search). Comparisons: %d\n", searchKey, comparisons);
}
else
{
printf("Key %d not found (successful search). Comparisons: %d\n", searchKey, comparisons);
}
// Unsuccessful search
searchKey = 55;
found = search(searchKey, &comparisons, 0);
if (found)
{
printf("Key %d found (unsuccessful search). Comparisons: %d\n", searchKey, comparisons);
}
else
{
printf("Key %d not found (unsuccessful search). Comparisons: %d\n", searchKey, comparisons);
}
// Free allocated memory
for (i = 0; i < TABLE_SIZE; i++)
{
Node* current = hashTable[i];
while (current != NULL)
{
Node* temp = current;
current = current->next;
free(temp);
}
}
return 0;
}
