#include "utils.h"

// https://leetcode.cn/problems/fibonacci-number/
// n [0, 30]
int fib_recur(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib_recur(n - 1) + fib_recur(n - 2);
}

static int memo[31] = {0};
int fib_recur_with_memo(int n) {
	if (n == 0) return memo[0] = 0;
	if (n == 1) return memo[1] = 1;
    if (memo[n] != 0) return memo[n];
    return memo[n] = fib_recur_with_memo(n - 1) + fib_recur_with_memo(n - 2);
}

int fib_iter(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}


TEST_CASE("DP with Fibonacci", "[Fibonacci]") {
    REQUIRE(fib_iter(5) == 5);
    REQUIRE(fib_recur(5) == 5);
    REQUIRE(fib_recur_with_memo(5) == 5);
}
