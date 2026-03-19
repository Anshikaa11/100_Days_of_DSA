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

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if(root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** ans = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));

    struct TreeNode* q[1000];
    int front = 0, rear = 0;
    q[rear++] = root;

    while(front < rear) {
        int size = rear - front;
        ans[*returnSize] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[*returnSize] = size;

        for(int i = 0; i < size; i++) {
            struct TreeNode* node = q[front++];
            ans[*returnSize][i] = node->val;

            if(node->left) q[rear++] = node->left;
            if(node->right) q[rear++] = node->right;
        }

        (*returnSize)++;
    }

    return ans;
}

int main() {
    printf("Solution for Binary Tree Level Order Traversal is implemented. Add test cases as needed.\n");
    return 0;
}