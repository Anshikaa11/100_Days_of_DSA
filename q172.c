#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int mySqrt(int x) {
    if(x == 0) return 0;

    int low = 1, high = x;
    int ans = 0;

    while(low <= high) {
        long long mid = low + (high - low) / 2;

        if(mid * mid <= (long long)x) {
            ans = (int)mid;
            low = (int)mid + 1;
        } else {
            high = (int)mid - 1;
        }
    }

    return ans;
}

int main() {
    printf("Solution for Sqrt(x) is implemented. Add test cases as needed.\n");
    return 0;
}