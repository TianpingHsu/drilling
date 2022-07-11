#include "utils.h"

class Solution {
    int ret = 0;
    int dfs(vector<vector<int>> &g, int i, int j) {
        int row = g.size(), col = g[0].size();
        if (i < 0 || i >= row) return 0;
        if (j < 0 || j >= col) return 0;
        if (g[i][j] == 0) return 0;
        g[i][j] = 0;
        int tmp = 1 + dfs(g, i - 1, j) + dfs(g, i + 1, j) + dfs(g, i, j + 1) + dfs(g, i, j - 1);
        return tmp;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (size_t row = 0; row < grid.size(); row++) {
            for (size_t col = 0; col < grid[0].size(); col++) {
                if (grid[row][col]) {
                    int tmp = dfs(grid, row, col);
                    if (tmp > ret) ret = tmp;
                }
            }
        }
        return ret;
    }

    void test() {
        vector<vector<int>> g;
        g.push_back(createVector("[0,0,1,0,0,0,0,1,0,0,0,0,0]"));
        g.push_back(createVector("[0,0,0,0,0,0,0,1,1,1,0,0,0]"));
        g.push_back(createVector("[0,1,1,0,1,0,0,0,0,0,0,0,0]"));
        g.push_back(createVector("[0,1,0,0,1,1,0,0,1,0,1,0,0]"));
        g.push_back(createVector("[0,1,0,0,1,1,0,0,1,1,1,0,0]"));
        g.push_back(createVector("[0,0,0,0,0,0,0,0,0,0,1,0,0]"));
        g.push_back(createVector("[0,0,0,0,0,0,0,1,1,1,0,0,0]"));
        g.push_back(createVector("[0,0,0,0,0,0,0,1,1,0,0,0,0]"));
        OUT(maxAreaOfIsland(g));
    }
};

