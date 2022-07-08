#include "utils.h"
/*
 brute force
class Solution {
    int ret = 999999999, tmp = 0;
    int rows, cols;
    vector<vector<bool>> vis;
    void dfs(vector<vector<int>> &g, int i, int j) {
        if (i >= rows || j >= cols) {
            return;
        }
        if (tmp > ret) return;
        if (i == rows - 1 && j == cols - 1) {
            if (ret > tmp + g[i][j]) ret = tmp + g[i][j];
            return;
        }
        if (vis[i][j]) return;
        vis[i][j] = true;
        tmp += g[i][j];
        // right
        dfs(g, i, j + 1);
        // down
        dfs(g, i + 1, j);
        vis[i][j] = false;
        tmp -= g[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        rows = grid.size();
        if (rows) cols = grid[0].size();
        for (size_t i = 0; i < rows; i++) {
            vector<bool> v;
            for (size_t j = 0; j < cols; j++) {
                v.push_back(false);
            }
            vis.push_back(v);
        }
        dfs(grid, 0, 0);
        return ret;
    }
};
*/
