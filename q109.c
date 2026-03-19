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

void rightView(struct Node* root) {
    if(root == NULL) return;

    struct Node* q[1000];
    int front = 0, rear = 0;
    q[rear++] = root;

    while(front < rear) {
        int size = rear - front;

        for(int i = 0; i < size; i++) {
            struct Node* temp = q[front++];

            if(i == size - 1)
                printf("%d ", temp->data);

            if(temp->left != NULL)
                q[rear++] = temp->left;
            if(temp->right != NULL)
                q[rear++] = temp->right;
        }
    }
}

int main() {
    printf("Solution for Right View of Binary Tree is implemented. Add test cases as needed.\n");
    return 0;
}