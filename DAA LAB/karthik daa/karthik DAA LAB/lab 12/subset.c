#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Function to print the subset
void printSubset(int subset[], int size)
{
int i;
printf("{ ");
for (i = 0; i < size; i++)
{
printf("%d ", subset[i]);
}
printf("}\n");
}
// Function to solve subset-sum problem using backtracking
bool subsetSum(int set[], int subset[], int setSize, int subsetSize, int sum, int targetSum, int index)
{
if (sum == targetSum)
{
printSubset(subset, subsetSize);
return true; // Found a solution
}
if (sum > targetSum || index >= setSize)
{
return false; // Cannot exceed target sum or reach end of set
}
// Include the current element
subset[subsetSize] = set[index];
if (subsetSum(set, subset, setSize, subsetSize + 1, sum + set[index], targetSum, index + 1))
{
//If we only want one solution, we can return true here.
}
// Exclude the current element
if (subsetSum(set, subset, setSize, subsetSize, sum, targetSum, index + 1))
{
//If we only want one solution, we can return true here.
}
return false;
}
int main( )
{
int set[ ] = {1, 2, 5, 6, 8};
int targetSum = 9;
int setSize = sizeof(set) / sizeof(set[0]);
int *subset = (int *)malloc(setSize * sizeof(int)); // Maximum subset size is setSize
if (subset == NULL)
{
printf("Memory allocation failed.\n");
return 1;
}
printf("Subsets with sum %d:\n", targetSum);
if(!subsetSum(set, subset, setSize, 0, 0, targetSum, 0))
{
printf("No subset found with sum %d.\n", targetSum);
}
free(subset);
return 0;
}
