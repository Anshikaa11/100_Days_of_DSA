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
    while(root != NULL) {
        if(p->val < root->val && q->val < root->val)
            root = root->left;
        else if(p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main() {
    printf("Solution for Lowest Common Ancestor of a BST is implemented. Add test cases as needed.\n");
    return 0;
}