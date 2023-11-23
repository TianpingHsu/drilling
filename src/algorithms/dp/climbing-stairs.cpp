#include "utils.h"

// https://leetcode.cn/problems/climbing-stairs/
// n [1, 45]


int climbing_stairs_recur(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return climbing_stairs_recur(n - 1) + climbing_stairs_recur(n - 2);
}

static int memo[46] = {0};
int climbing_stairs_recur_with_memo(int n) {
    if (n == 1) return memo[n] = 1;
    if (n == 2) return memo[n] = 2;

    return memo[n] = climbing_stairs_recur_with_memo(n - 1) + climbing_stairs_recur_with_memo(n - 2);
}

int climbing_stairs_iter(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int a = 1;
    int b = 2;
    for (int i = 3; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

TEST_CASE("DP with climbing stairs", "[ClimbingStairs]") {
    REQUIRE(climbing_stairs_recur(5) == 8);
    REQUIRE(climbing_stairs_recur_with_memo(5) == 8);
    REQUIRE(climbing_stairs_iter(5) == 8);
}
