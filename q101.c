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
    while(root != NULL) {
        if(n1 < root->data && n2 < root->data)
            root = root->left;
        else if(n1 > root->data && n2 > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main() {
    printf("Solution for Lowest Common Ancestor in BST is implemented. Add test cases as needed.\n");
    return 0;
}