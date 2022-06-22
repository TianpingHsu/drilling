class Solution {
    int lands = 0;
    int row = 0, col = 0;
    void dfs(vector<vector<char>> &grid, int r, int c) {
        if (r < 0 || r >= row) return;
        if (c < 0 || c >= col) return;
        if (grid[r][c] == '1') {
            grid[r][c] = '0';
            dfs(grid, r, c - 1);
            dfs(grid, r, c + 1);
            dfs(grid, r - 1, c);
            dfs(grid, r + 1, c);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        if (row) col = grid[0].size();
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == '1') {
                    lands++;
                    dfs(grid, r, c);
                }
            }
        }
        return lands;
    }
}; 
