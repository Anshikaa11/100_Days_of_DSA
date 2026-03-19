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

struct Node* LCA(struct Node* root, int n1, int n2) {
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    struct Node* left = LCA(root->left, n1, n2);
    struct Node* right = LCA(root->right, n1, n2);

    if(left != NULL && right != NULL)
        return root;

    if(left != NULL)
        return left;

    return right;
}

int main() {
    printf("Solution for LCA in Binary Tree is implemented. Add test cases as needed.\n");
    return 0;
}