
#include "utils.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        flip(matrix);
    }

    void transpose(vector<vector<int>> & matrix) {
       int rows = matrix.size();
       int cols = matrix[0].size();
       for (int row = 0; row < rows; row++) {
           for (int col = row + 1; col < cols; col++) {
               std::swap(matrix[row][col], matrix[col][row]);
           }
       }
    }

    void flip(vector<vector<int>> &matrix) {
       int n = matrix.size(); 
       int i = 0, j = n - 1;
       while (i < j) {
           for (int k = 0; k < n; k++) {
               std::swap(matrix[k][i], matrix[k][j]);
           }
           i++, j--;
       }
    }
#ifdef TEST
    void test() {
        //vector<vector<int>> m = createMatrix("[[1,2,3],[4,5,6],[7,8,9]]");
        vector<vector<int>> m;
        m.push_back(createVector("[1,2,3]"));
        m.push_back(createVector("[4,5,6]"));
        m.push_back(createVector("[7,8,9]"));
        rotate(m);
        for (auto row : m)
            PRINT_VEC(row);
    }
#endif
};
