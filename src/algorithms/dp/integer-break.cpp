#include "utils.h"

// https://leetcode.cn/problems/integer-break/

int memo[64];
int integer_break_recur_with_memo(int n) {
    if (memo[n] != INT_MIN) return memo[n];

    int opt = n - 1;
    for (int i = 1; i < n - 1; i++) {
        int tmp = std::max(integer_break_recur_with_memo(n - i), n - i);
        if (opt < i * tmp) opt = i * tmp;
    }
    return memo[n] = opt;
}

int integer_break_iter(int n) {
    for (int i = 2; i < sizeof(memo)/sizeof(int) && i <= n; i++) {
        memo[i] = INT_MIN;
    }
    memo[2] = 1;
    for (int i = 3; i <= n; i++) {
        int opt = i - 1;
        for (int k = 1; k <= i - 2; k++) {
            int tmp = k * std::max(memo[i - k], i - k);
            if (opt < tmp) opt = tmp;
        }
        memo[i] = opt;
    }
    return memo[n];
}

TEST_CASE("DP with integerBreak", "[.][integerBreak]") {
    REQUIRE(integer_break_iter(2) == 1);
    REQUIRE(integer_break_iter(10) == 36);

    for (int i = 2; i < sizeof(memo)/sizeof(int); i++) {
        memo[i] = INT_MIN;
    }
    memo[2] = 1;
    REQUIRE(integer_break_recur_with_memo(10) == 36);
}
