#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int search(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    printf("Solution for Binary Search is implemented. Add test cases as needed.\n");
    return 0;
}