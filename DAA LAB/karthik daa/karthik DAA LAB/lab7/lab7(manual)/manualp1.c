#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
int data;
struct Node *left;
struct Node *right;
int height; // Added height for balance factor calculation
} Node;
Node *createNode(int data)
{
Node *newNode = (Node *)malloc(sizeof(Node));
if (newNode == NULL)
{
fprintf(stderr, "Memory allocation failed\n");
exit(EXIT_FAILURE);
}
newNode->data = data;
newNode->left = NULL;
newNode->right = NULL;
newNode->height = 0; // Initialize height
return newNode;
}
int getHeight(Node *node)
{
if (node == NULL)
{
return 0;
}
return node->height;
}
int getBalanceFactor(Node *node)
{
if (node == NULL)
{
return 0;
}
return getHeight(node->left) - getHeight(node->right);
}
int max(int a, int b)
{
return (a > b) ? a : b;
}
Node *insert(Node *root, int data)
{
if (root == NULL)
{
return createNode(data);
}
if (data < root->data)
{
root->left = insert(root->left, data);
} else if (data > root->data)
{
root->right = insert(root->right, data);
} // Duplicate keys are ignored
// Update height after insertion
root->height = 1 + max(getHeight(root->left), getHeight(root->right));
return root;
}
void printBalanceFactors(Node *root)
{
if (root != NULL)
{
printBalanceFactors(root->left);
printf("Node: %d, Balance Factor: %d\n", root->data, getBalanceFactor(root));
printBalanceFactors(root->right);
}
}
void freeTree(Node *root)
{
if (root != NULL)
{
freeTree(root->left);
freeTree(root->right);
free(root);
}
}
int main()
{
Node *root = NULL;
//int keys[] = {40, 20, 10, 25, 30, 22, 50}; //input-1
int keys[] = {50, 30, 20, 40, 70, 60, 80}; ////input-2
//int keys[] = {1, 2, 3, 4, 5, 6}; //input-3
int n = sizeof(keys) / sizeof(keys[0]);
int i;
for (i = 0; i < n; i++)
{
root = insert(root, keys[i]);
}
printf("Balance factors of nodes in the BST:\n");
printBalanceFactors(root);
freeTree(root); // Free allocated memory
return 0;
}
