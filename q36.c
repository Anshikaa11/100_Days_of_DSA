#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* answer = (int*)malloc(numsSize * sizeof(int));
    
    *returnSize = numsSize;

    // Step 1: Prefix products
    answer[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Step 2: Suffix products
    int suffix = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] = answer[i] * suffix;
        suffix *= nums[i];
    }

    return answer;
}

int main() {
    printf("Solution for Product of Array Except Self is implemented. Add test cases as needed.\n");
    return 0;
}