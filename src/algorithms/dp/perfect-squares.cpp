#include "utils.h"

// https://leetcode.cn/problems/perfect-squares/

static vector<int> squares;
static int memo[128][10000];

int perfect_squares(int n) {
    // pre-process, get goods
    squares.clear();
    for (int i = 1; i * i <= n; i++) {
        squares.push_back(i * i);
    }

    // do init
    int size = std::sqrt(n);    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= n; j++) {
            memo[i][j] = INT_MAX - 10000;
        }
        memo[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) memo[0][i] = i;

    // iteration
    // memo[i][j] = min{memo[i - 1][j], memo[i][j - squares[i]] + 1}
    for (int i = 1; i < squares.size(); i++) {
        //cout << "\n" << "iter: " << i << endl;
        for (int j = 1; j <= n; j++) {
            int a = memo[i - 1][j];
            int b = INT_MAX;
            if (j >= squares[i]) b = memo[i][j - squares[i]] + 1;
            memo[i][j] = std::min(a, b);
        }
        //SHOW2D(memo, size, n + 1);
    }

    return memo[squares.size() - 1][n];
}

int numSquares(int n) {
    return perfect_squares(n);
}

TEST_CASE("DP with numSquares", "[.][numSquares]") {
    REQUIRE(numSquares(12) == 3);
    REQUIRE(numSquares(13) == 2);
}
