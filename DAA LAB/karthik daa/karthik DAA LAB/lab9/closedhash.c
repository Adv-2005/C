#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
typedef struct
{
int key;
int occupied; // 0: empty, 1: occupied
} HashEntry;
int hashFunction(int key)
{
return key % TABLE_SIZE;
}
int insert(HashEntry *table, int key)
{
int index = hashFunction(key);
int originalIndex = index;
do
{
if (table[index].occupied == 0)
{
table[index].key = key;
table[index].occupied = 1;
return 1; // Insertion successful
}
index = (index + 1) % TABLE_SIZE;
} while (index != originalIndex);
return 0; // Table is full
}
int search(HashEntry *table, int key, int *comparisons)
{
int index = hashFunction(key);
int originalIndex = index;
*comparisons = 1; // Initial comparison
do
{
if (table[index].occupied == 1 && table[index].key == key)
{
return 1; // Key found
}
*comparisons += 1;
index = (index + 1) % TABLE_SIZE;
} while (table[index].occupied != 0 && index != originalIndex);
return 0; // Key not found
}
int unsuccessfulSearchComparisons(HashEntry *table, int key)
{
int index = hashFunction(key);
int originalIndex = index;
int comparisons = 1;
do
{
if (table[index].occupied == 0)
{
return comparisons;
}
comparisons++;
index = (index + 1) % TABLE_SIZE;
} while (index != originalIndex);
return comparisons;
}
int main()
{
HashEntry hashTable[TABLE_SIZE];
int keys[] = {5, 25, 15, 36, 26, 7, 17, 47};
int numKeys = sizeof(keys) / sizeof(keys[0]);
int comparisons;
int i;
// Initialize the hash table
for (i = 0; i < TABLE_SIZE; i++)
{
hashTable[i].occupied = 0;
}
// Insert keys
for (i = 0; i < numKeys; i++)
{
insert(hashTable, keys[i]);
}
// Successful search example
int searchKey = 15;
if (search(hashTable, searchKey, &comparisons))
{
printf("Successful Search:\n");
printf("Key %d found, comparisons: %d\n", searchKey, comparisons);
}
else
{
printf("Key %d not found\n", searchKey);
}
// Unsuccessful search example
searchKey = 16;
if (search(hashTable, searchKey, &comparisons))
{
printf("Key %d found, comparisons: %d\n", searchKey, comparisons);
}
else
{
printf("\nUnsuccessful Search:\n");
printf("Key %d not found, comparisons: %d\n", unsuccessfulSearchComparisons(hashTable, searchKey));
}
return 0;
}
