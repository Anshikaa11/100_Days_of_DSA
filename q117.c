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

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findIndex(int inorder[], int start, int end, int val) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == val)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if(inStart > inEnd)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;
    struct Node* root = createNode(rootVal);

    if(inStart == inEnd)
        return root;

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

void preorder(struct Node* root) {
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    printf("Solution for Build Tree from Inorder & Postorder is implemented. Add test cases as needed.\n");
    return 0;
}