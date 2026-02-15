#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int maxSubArray(int* nums, int numsSize) {
    int maxSum = nums[0];
    int currSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (currSum < 0)
            currSum = nums[i];
        else
            currSum += nums[i];

        if (currSum > maxSum)
            maxSum = currSum;
    }

    return maxSum;
}

int main() {
    printf("Solution for Maximum Subarray is implemented. Add test cases as needed.\n");
    return 0;
}