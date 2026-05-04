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

int* BIT;
int size;

void update(int i) {
    while (i <= size) {
        BIT[i] += 1;
        i += (i & -i);
    }
}

int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= (i & -i);
    }
    return sum;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int* sorted = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) sorted[i] = nums[i];
    qsort(sorted, numsSize, sizeof(int), compare);

    BIT = (int*)calloc(numsSize + 1, sizeof(int));
    size = numsSize;

    int* result = (int*)malloc(numsSize * sizeof(int));

    for (int i = numsSize - 1; i >= 0; i--) {
        int rank = 1;
        while (rank <= numsSize && sorted[rank - 1] != nums[i]) rank++;
        result[i] = query(rank - 1);
        update(rank);
    }

    *returnSize = numsSize;
    return result;
}

int main() {
    printf("Solution for Count of Smaller Numbers After Self is implemented. Add test cases as needed.\n");
    return 0;
}