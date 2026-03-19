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

int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if(root == NULL) return NULL;

    int* ans = (int*)malloc(1000 * sizeof(int));
    struct TreeNode* q[1000];
    int front = 0, rear = 0;
    q[rear++] = root;

    while(front < rear) {
        int size = rear - front;

        for(int i = 0; i < size; i++) {
            struct TreeNode* node = q[front++];

            if(i == size - 1)
                ans[(*returnSize)++] = node->val;

            if(node->left) q[rear++] = node->left;
            if(node->right) q[rear++] = node->right;
        }
    }

    return ans;
}

int main() {
    printf("Solution for Binary Tree Right Side View is implemented. Add test cases as needed.\n");
    return 0;
}