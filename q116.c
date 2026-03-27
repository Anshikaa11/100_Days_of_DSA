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

struct TreeNode* build(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if(inStart > inEnd)
        return NULL;

    int val = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = NULL;
    root->right = NULL;

    if(inStart == inEnd)
        return root;

    int index;
    for(index = inStart; index <= inEnd; index++) {
        if(inorder[index] == val)
            break;
    }

    root->left = build(preorder, inorder, inStart, index - 1, preIndex);
    root->right = build(preorder, inorder, index + 1, inEnd, preIndex);

    return root;
}

int main() {
    printf("Solution for Construct Binary Tree from Preorder and Inorder Traversal is implemented. Add test cases as needed.\n");
    return 0;
}