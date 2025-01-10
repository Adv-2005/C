#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* node, int key) {
    if (node == NULL) return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

int search(struct TreeNode* node, int key) {
    if (node == NULL) return 0;
    if (node->key == key) return 1;

    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

void insertOrSearch(struct TreeNode** root, int key) {
    if (search(*root, key)) {
        printf("key found\n");
    } else {
        *root = insert(*root, key);
        printf("%d inserted\n", key);
    }
}

int main() {
    struct TreeNode* root = NULL;

    insertOrSearch(&root, 10);
    insertOrSearch(&root, 5);
    insertOrSearch(&root, 20);
    insertOrSearch(&root, 10);

    return 0;
}

