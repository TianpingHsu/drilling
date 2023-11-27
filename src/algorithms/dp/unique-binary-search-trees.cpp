#include "utils.h"

// https://leetcode.cn/problems/unique-binary-search-trees/
// 1 <= n <= 19

static int memo[32];
int unique_binary_search_trees_recur_with_memo(const int n) {
    if (memo[n] != INT_MIN) return memo[n];

    int ret = 0;
    for (int i = 1; i <= n; i++) {
        int l = unique_binary_search_trees_recur_with_memo(i - 1);
        int r = unique_binary_search_trees_recur_with_memo(n - i);
        ret += l * r;
    }
    return memo[n] = ret;
}

int unique_binary_search_trees_iter(int n) {
    for (int i = 0; i < 32; i++) {
        memo[i] = 0;
    }
    memo[0] = 1;
    memo[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            memo[i] += memo[j - 1] * memo[i - j];
        }
    }
    //for (int i = 1; i <= n; i++) OUT(memo[i]);
    return memo[n];
}

int numTrees(int n, int type) {
    if (type == 0) {
        for (int i = 0; i < 32; i++) {
            memo[i] = INT_MIN;
        }
        memo[0] = 1;
        memo[1] = 1;
        memo[2] = 2;
        return unique_binary_search_trees_recur_with_memo(n);
    } else {
        return unique_binary_search_trees_iter(n);
    }
}

TEST_CASE("DP with numTrees", "[.][numTrees]") {
    //REQUIRE(numTrees(3, 1) == 5);
    //REQUIRE(numTrees(1, 1) == 1);
    REQUIRE(numTrees(3, 0) == 5);
    REQUIRE(numTrees(1, 0) == 1);
}

