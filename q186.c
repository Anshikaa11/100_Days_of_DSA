#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include <stdio.h>

void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int partition(int* nums, int low, int high) {
    int pivot = nums[low];
    int j = low;

    for (int i = low + 1; i <= high; i++) {
        if (nums[i] < pivot) {
            j++;
            swap(nums, i, j);
        }
    }
    swap(nums, low, j);
    return j;
}

int QSelect(int* nums, int low, int high, int k) {
    if (low <= high) {
        int p = partition(nums, low, high);

        if (p == k) return nums[p];
        if (p < k) return QSelect(nums, p + 1, high, k);
        else return QSelect(nums, low, p - 1, k);
    }
    return nums[low];
}

int findKthLargest(int* nums, int numsSize, int k) {
    return QSelect(nums, 0, numsSize - 1, numsSize - k);
}

int main() {
    printf("Solution for Kth Largest Element in an Array is implemented. Add test cases as needed.\n");
    return 0;
}