#include "utils.h"

// https://leetcode.cn/problems/unique-paths/
// 1 <= m, n <= 100

int unique_paths_recur(const int m, const int n, int r, int c) {
    if (r == m - 1 && c == n - 2) return 1;
    if (r == m - 2 && c == n - 1) return 1;
    if (r == m - 1) {  // bottom most
        return unique_paths_recur(m, n, r, c + 1);
    }
    if (c == n - 1) {  // right most
        return unique_paths_recur(m, n, r + 1, c);
    }

    int a = 1 + unique_paths_recur(m, n, r, c + 1);  // go right
    int b = 1 + unique_paths_recur(m, n, r + 1, c);  // go down
    return a + b;
}


static int memo[128][128];
int unique_paths_recur_with_memo(const int m, const int n, int r, int c) {
    if (r == m - 1 && c == n - 2) return 1;
    if (r == m - 2 && c == n - 1) return 1;
    if (memo[r][c] != INT_MIN) return memo[r][c];

    if (r == m - 1) {  // bottom most
        return memo[r][c] = 1;
    }
    if (c == n - 1) {  // right most
        return memo[r][c] = 1;
    }

    int a = unique_paths_recur_with_memo(m, n, r, c + 1);  // go right
    int b = unique_paths_recur_with_memo(m, n, r + 1, c);  // go down
    return memo[r][c] = a + b;

}

int unique_paths_iter(const int m, const int n) {
    //std::fill(&memo[0][0], &memo[0][0] + 128 * 128 * sizeof(int), INT_MIN);
    std::fill(&memo[0][0], &memo[0][0] + 128 * 128, INT_MIN);
    for (int i = 0; i < m; i++) memo[i][0] = 1;
    for (int j = 0; j < n; j++) memo[0][j] = 1;

    for (int r = 1; r < m; r++) {
        for (int c = 1; c < n; c++) {
            memo[r][c] = memo[r - 1][c] + memo[r][c - 1];
        }
    }
    return memo[m - 1][n - 1];
}

int uniquePaths(int m, int n, int type) {
    switch (type) {
        case SOLUTION_TOP_DOWN_WITH_MEMO:
            //std::fill(&memo[0][0], &memo[0][0] + 128 * 128, INT_MIN);
            for (int i = 0; i < 128; i ++) {
                for (int j = 0; j < 128; j++) {
                    memo[i][j] = INT_MIN;
                }
            }
            for (int i = 0; i < m; i++) memo[i][n - 1] = 1;
            for (int j = 0; j < n; j++) memo[m - 1][j] = 1;
            unique_paths_recur_with_memo(m, n, 0, 0);
            //return memo[m - 1][n - 1];
            return memo[0][0];
        case SOLUTION_BOTTOM_UP:
            return unique_paths_iter(m, n);
        default:
            return INT_MAX;
    }
}

TEST_CASE("DP with uniquePaths", "[.][uniquePaths]") {
    REQUIRE(uniquePaths(3, 7, SOLUTION_TOP_DOWN_WITH_MEMO) == 28);
    REQUIRE(uniquePaths(3, 7, SOLUTION_BOTTOM_UP) == 28);
    REQUIRE(uniquePaths(3, 2, SOLUTION_TOP_DOWN_WITH_MEMO) == 3);
    REQUIRE(uniquePaths(3, 2, SOLUTION_BOTTOM_UP) == 3);
    REQUIRE(uniquePaths(1, 2, SOLUTION_TOP_DOWN_WITH_MEMO) == 1);
}
