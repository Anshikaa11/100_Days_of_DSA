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

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int isMinHeap(struct Node* root) {
    if(root == NULL)
        return 1;

    if(root->left != NULL && root->data > root->left->data)
        return 0;

    if(root->right != NULL && root->data > root->right->data)
        return 0;

    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    printf("Solution for Validate Min-Heap is implemented. Add test cases as needed.\n");
    return 0;
}