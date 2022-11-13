#include "utils.h"

class Solution {
    int memo[64];
    int dp(int n) {
        if (memo[n] != -1) return memo[n];
        return memo[n] = dp(n - 1) + dp(n - 2);
    }
public:
    int climbStairs(int n) {
        memset(memo, -1, sizeof(int) * 64);
        memo[0] = 1;
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 3;
        return dp(n);
    }
};
