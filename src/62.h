class Solution {
    const static int MAX_N = 128;
    int memo[MAX_N][MAX_N];
    int _m, _n;
    int dfs(int i, int j) {
        if (i > _m || j > _n) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        int r = dfs(i, j + 1), d = dfs(i + 1, j);
        return memo[i][j] = r + d;
    }

public:
    int uniquePaths(int m, int n) {
        memset(memo[0], -1, sizeof(int) * MAX_N * MAX_N);
        _m = m, _n = n;
        memo[m][n] = 1;
        memo[m - 1][n] = 1;
        memo[m][n - 1] = 1;
        return dfs(1, 1);
    }
};
