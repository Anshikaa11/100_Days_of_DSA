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

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL || root == p || root == q)
        return root;

    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left != NULL && right != NULL)
        return root;

    if(left != NULL)
        return left;

    return right;
}

int main() {
    printf("Solution for Lowest Common Ancestor of a Binary Tree is implemented. Add test cases as needed.\n");
    return 0;
}