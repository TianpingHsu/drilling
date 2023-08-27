

#include "inc/utils.h"

class Solution {
    int memo[64];
public:
    /**
     * recursive version
        int climbStairs(int n) {
            memset(memo, 0, sizeof(memo));
            memo[0] = 0;
            memo[1] = 1;
            memo[2] = 2;

            return dfs(n);
        }

        int dfs(int k) {
            if (memo[k] != 0) return memo[k];
            return memo[k] = dfs(k - 1) + dfs(k - 2);
        }
    */
    int climbStairs(int n) {
        memset(memo, 0, sizeof(memo));
        memo[1] = 1;
        memo[2] = 2;
        for (int i = 3; i <= n; i++) {
            memo[i] = memo[ i - 1 ] + memo[i - 2];
        }
        return memo[n];
    }
};

