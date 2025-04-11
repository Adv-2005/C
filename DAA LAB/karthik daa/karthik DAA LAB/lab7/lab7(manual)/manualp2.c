#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
int data;
struct Node *left;
struct Node *right;
int height;
} Node;
int getHeight(Node *node)
{
if (node == NULL)
{
return 0;
}
return node->height;
}
int getBalance(Node *node)
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
newNode->height = 1;
return newNode;
}
Node *rightRotate(Node *y)
{
Node *x = y->left;
Node *T2 = x->right;
x->right = y;
y->left = T2;
y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
return x;
}
Node *leftRotate(Node *x)
{
Node *y = x->right;
Node *T2 = y->left;
y->left = x;
x->right = T2;
x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
return y;
}
Node *insert(Node *root, int data)
{
Node *stack[100]; // Assuming maximum height of 100
int top = -1;
Node *current = root;
Node *parent = NULL;
Node *newNode = createNode(data);
if (root == NULL)
{
return newNode;
}
while (current != NULL)
{
stack[++top] = current;
parent = current;
if (data < current->data)
{
current = current->left;
} else if (data > current->data)
{
current = current->right;
} else {
free(newNode);
return root; // Duplicate keys not allowed
}
}
if (data < parent->data)
{
parent->left = newNode;
} else {
parent->right = newNode;
}
while (top >= 0) {
Node *node = stack[top--];
node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
int balance = getBalance(node);
if (balance > 1)
{
if (data < node->left->data)
{
if(node == root) root = rightRotate(node);
else if(parent->left == node) parent->left = rightRotate(node);
else parent->right = rightRotate(node);
if(top >=0) parent = stack[top];
}
else
{
node->left = leftRotate(node->left);
if(node == root) root = rightRotate(node);
else if(parent->left == node) parent->left = rightRotate(node);
else parent->right = rightRotate(node);
if(top >= 0) parent = stack[top];
}
}
else if (balance < -1)
{
if (data > node->right->data)
{
if(node == root) root = leftRotate(node);
else if(parent->left == node) parent->left = leftRotate(node);
else parent->right = leftRotate(node);
if(top >= 0) parent = stack[top];
}
else
{
node->right = rightRotate(node->right);
if(node == root) root = leftRotate(node);
else if(parent->left == node) parent->left = leftRotate(node);
else parent->right = leftRotate(node);
if(top >= 0) parent = stack[top];
}
}
}
return root;
}
void inorder(Node *root)
{
if (root != NULL)
{
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
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
int keys[] = {10, 20, 30, 40, 50, 25};
int n = sizeof(keys) / sizeof(keys[0]);
int i;
for (i = 0; i < n; i++)
{
root = insert(root, keys[i]);
}
printf("Inorder traversal of AVL tree: ");
inorder(root);
printf("\n");
freeTree(root);
return 0;
}
