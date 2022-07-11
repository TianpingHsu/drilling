class Solution {
    int memo[128];
    int dp(int n) {
        if (memo[n] != -1) return memo[n];
        int tmp = 1;
        for (int i = 1; i < n; i++) {
            int x = i * std::max(n - i, dp(n - i));
            if (tmp < x) tmp = x;
        }
        return memo[n] = tmp;
    }
public:
    int cuttingRope(int n) {
        memset(memo, -1, sizeof(memo));
        memo[2] = 1;
        memo[3] = 2;
        memo[4] = 4;
        memo[5] = 6;
        return dp(n);
    }
};
