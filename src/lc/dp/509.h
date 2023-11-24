
#include "utils.h"

class Solution {
public:
#define MAX_LEN 32
    int memo[MAX_LEN];
    int fib(int n) {
        memset(memo, -1, sizeof(int) * MAX_LEN);
        memo[0] = 0;
        memo[1] = 1;
        return fib_help(n);
    }

    int fib_help(int n) {
        if (memo[n] != -1) return memo[n];
        return memo[n] = fib_help(n - 1) + fib_help(n - 2);
    }
#ifdef TEST
    void test() {
        CHECK(fib(3), 2);
        CHECK(fib(4), 3);
    }
#endif
};
