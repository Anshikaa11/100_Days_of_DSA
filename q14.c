#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        
        int prev2 = 0, prev1 = 1;
        
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};

int main() {
    printf("Solution for Fibonacci Number is implemented. Add test cases as needed.\n");
    return 0;
}