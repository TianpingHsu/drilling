class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int, int>> s;
        size_t rows = matrix.size(), cols = rows ? matrix[0].size() : 0;
        for (size_t i = 0; i < matrix.size(); i++) {
            vector<int> &v = matrix[i];
            for (size_t j = 0; j < v.size(); j++) {
                if (matrix[i][j] == 0) s.insert({i, j});
            }
        }
        for (auto p : s) {
            int row = p.first, col = p.second;
            for (size_t c = 0; c < cols; c++) matrix[row][c] = 0;
            for (size_t r = 0; r < rows; r++) matrix[r][col] = 0;
        }
    }
};
