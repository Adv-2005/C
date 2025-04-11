#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *left;
    int value;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->value = value;
    return temp;
}

struct Node *insertNode(struct Node *node, int value) {
    if (node == NULL) {
        node = createNode(value);
        return node;
    }
    if (value < node->value)
        node->left = insertNode(node->left, value);
    else
        node->right = insertNode(node->right, value);

    return node;
}

int height(struct Node *node) {
    if (!node) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void inorder(struct Node *node) {
    if (!node) return;
    inorder(node->left);
    printf("\n%p -> %d", node, node->value);
    inorder(node->right);
}

void preorder(struct Node *node) {
    if (!node) return;
    printf("\n%p -> %d", node, node->value);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct Node *node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    printf("\n%p -> %d", node, node->value);
}

int main() {
    int a[] = {7, 12, 18, 10, 27, 3, 5, 4, 45};
    int n = sizeof(a) / sizeof(int);
    struct Node *root = NULL;int i;

    for ( i = 0; i < n; i++) {
        root = insertNode(root, a[i]);
    }

    printf("THE INORDER SEQUENCE IS:\n");
    inorder(root);

    printf("\nTHE PREORDER SEQUENCE IS:\n");
    preorder(root);

    printf("\nTHE POSTORDER SEQUENCE IS:\n");
    postorder(root);

    return 0;
}
