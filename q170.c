#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int findMin(int* nums, int numsSize) {
    int low = 0, high = numsSize - 1;

    while(low < high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] > nums[high])
            low = mid + 1;
        else
            high = mid;
    }

    return nums[low];
}

int main() {
    printf("Solution for Find Minimum in Rotated Sorted Array is implemented. Add test cases as needed.\n");
    return 0;
}