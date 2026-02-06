#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};

int main() {
    printf("Solution for Power of Two is implemented. Add test cases as needed.\n");
    return 0;
}