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

void flatten(struct TreeNode* root) {
    if(root == NULL)
        return;

    flatten(root->left);
    flatten(root->right);

    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;

    root->left = NULL;
    root->right = left;

    struct TreeNode* curr = root;
    while(curr->right != NULL)
        curr = curr->right;

    curr->right = right;
}

int main() {
    printf("Solution for Flatten Binary Tree to Linked List is implemented. Add test cases as needed.\n");
    return 0;
}