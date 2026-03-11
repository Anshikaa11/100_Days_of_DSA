#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int inorder(int* arr, struct TreeNode* root, int index) {
    if (root != NULL) {
        index = inorder(arr, root->left, index);
        arr[index++] = root->val;
        index = inorder(arr, root->right, index);
    }
    return index;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(100 * sizeof(int));
    *returnSize = inorder(arr, root, 0);
    return arr;
}

int main() {
    printf("Solution for Binary Tree Inorder Traversal is implemented. Add test cases as needed.\n");
    return 0;
}