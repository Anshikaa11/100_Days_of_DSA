#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int findPeakElement(int* nums, int numsSize) {
    int low = 0, high = numsSize - 1;

    while(low < high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] > nums[mid + 1])
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    printf("Solution for Find Peak Element is implemented. Add test cases as needed.\n");
    return 0;
}