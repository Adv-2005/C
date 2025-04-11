#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* searchAndInsert(Node* root, int key) {
    if (root == NULL) {
        printf("Key not found. Inserting key %d.\n", key);
        return createNode(key);
    }

    if (key < root->data) {
        root->left = searchAndInsert(root->left, key);
    } else if (key > root->data) {
        root->right = searchAndInsert(root->right, key);
    } else {
        printf("Key found.\n");
    }
    return root;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int keys[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(keys) / sizeof(keys[0]);int i;

    for ( i = 0; i < n; i++) {
        root = searchAndInsert(root, keys[i]);
    }

    int searchKey = 40;
    searchAndInsert(root, searchKey);

    printf("In-order traversal of the BST: ");
    inOrder(root);
    printf("\n");

    return 0;
}
