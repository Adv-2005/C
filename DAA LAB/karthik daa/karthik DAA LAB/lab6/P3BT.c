#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Structure for a binary tree node
struct Node
{
int data;
struct Node *left;
struct Node *right;
};
// Function to create a new node
struct Node* createNode(int data)
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}
// Function to count the total number of nodes in the tree
int countNodes(struct Node* root)
{
if (root == NULL)
{
return 0;
} else
{
return 1 + countNodes(root->left) + countNodes(root->right);
}
}
// Function to build a *complete* binary tree (for consistent testing)
struct Node* buildCompleteTree(int arr[], int start, int end)
{
if (start > end)
{
return NULL;
}
int mid = (start + end) / 2;
struct Node* root = createNode(arr[mid]);
root->left = buildCompleteTree(arr, start, mid - 1);
root->right = buildCompleteTree(arr, mid + 1, end);
return root;
}
int main()
{
int n,i;
printf("Enter the number of nodes for the complete binary tree: ");
scanf("%d", &n);
int *arr = (int *)malloc(n * sizeof(int)); //Dynamically allocate memory
if (arr == NULL)
{
perror("Memory allocation failed");
return 1;
}
// Fill the array with values (for the complete binary tree)
for (i = 0; i < n; i++)
{
arr[i] = i+1; // Or any other sequence of values
}
struct Node* root = buildCompleteTree(arr, 0, n - 1); // Build the tree
clock_t start, end;
double cpu_time_used;
start = clock();
int nodeCount = countNodes(root);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Number of nodes: %d\n", nodeCount); // Verify the count
printf("Time taken to count nodes in a tree of size %d: %f seconds\n", n, cpu_time_used);
free(arr); // Free the dynamically allocated memory
// (You would also need to free the tree nodes if you were not just counting)
return 0;
}
