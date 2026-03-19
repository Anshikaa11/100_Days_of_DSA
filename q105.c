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

struct Pair {
    struct Node* node;
    int hd;
};

void verticalOrder(struct Node* root) {
    if(root == NULL) return;

    struct Pair q[1000];
    int front = 0, rear = 0;

    int hdArr[1000];
    int valArr[1000];
    int count = 0;

    q[rear].node = root;
    q[rear].hd = 0;
    rear++;

    while(front < rear) {
        struct Pair cur = q[front++];
        struct Node* temp = cur.node;
        int hd = cur.hd;

        hdArr[count] = hd;
        valArr[count] = temp->data;
        count++;

        if(temp->left != NULL) {
            q[rear].node = temp->left;
            q[rear].hd = hd - 1;
            rear++;
        }

        if(temp->right != NULL) {
            q[rear].node = temp->right;
            q[rear].hd = hd + 1;
            rear++;
        }
    }

    for(int i = -100; i <= 100; i++) {
        int printed = 0;
        for(int j = 0; j < count; j++) {
            if(hdArr[j] == i) {
                printf("%d ", valArr[j]);
                printed = 1;
            }
        }
        if(printed)
            printf("\n");
    }
}

int main() {
    printf("Solution for Print Binary Tree Vertical Order is implemented. Add test cases as needed.\n");
    return 0;
}