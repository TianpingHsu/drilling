

#include "inc/utils.h"

// https://leetcode.cn/problems/perfect-squares/
class Solution {
    vector<int> squares;
    map<int, int> memo;
    const static int s_max = 1000000;
public:
    Solution(): memo{{1, 1}} {}
    int dfs(int n, int k) {
        if (n < 0 || k < 0) return s_max;
        if (memo.find(n) != memo.end()) return memo[n];
        if (n == 0) return 0;
        if (sqrt(n) * sqrt(n) == n) return 1;
        int a = s_max, b = s_max;
        if (n - squares[k] < 0) {
            a = dfs(n, k - 1);
        } else {
            a = 1 + dfs(n - squares[k], k);
            b = dfs(n, k - 1);
        }
        //cout << "n: " << n << " k: " << k << " a: " << a << " b: " << b << endl;
        return memo[n] = std::min(a, b);
    }

    int numSquares(int n) {
        for (int i = 1, sqr = i * i; sqr <= n;) {
            squares.push_back(sqr);
            i++;
            sqr = i * i;
        }
#ifdef TEST
        PRINT_VEC(squares);
#endif
        return dfs(n, squares.size() - 1);
    }

#ifdef TEST
    void test() {
        CHECK(numSquares(12), 3);
        //CHECK(numSquares(13), 2);
    }
#endif

};

