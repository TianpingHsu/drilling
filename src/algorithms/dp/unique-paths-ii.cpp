
#include "utils.h"

// https://leetcode.cn/problems/unique-paths-ii/

/*
    m == obstacleGrid.length
    n == obstacleGrid[i].length
    1 <= m, n <= 100
    obstacleGrid[i][j] 为 0 或 1
*/

static int memo[128][128];
int unique_paths_with_obstacles_recur_with_memo(vector<vector<int>>& obstacleGrid, int r, int c) {
    const int m = obstacleGrid.size(), n = obstacleGrid[0].size();    
    if (r == 0 && c == 0) return 1;
    if (memo[r][c] != INT_MIN) return memo[r][c];
    if (obstacleGrid[r][c] == 1) return memo[r][c] = 0;

    int a = unique_paths_with_obstacles_recur_with_memo(obstacleGrid, r - 1, c);
    int b = unique_paths_with_obstacles_recur_with_memo(obstacleGrid, r, c - 1);
    return memo[r][c] = a + b;
}

int unique_paths_with_obstacles_iter(vector<vector<int>>& obstacleGrid) {
    const int m = obstacleGrid.size(), n = obstacleGrid[0].size();    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            memo[i][j] = INT_MIN;
            if (obstacleGrid[i][j] == 1) memo[i][j] = 0;
        }
    }
    bool ob = false;
    for (int i = 0; i < m; i++) {
        if (!obstacleGrid[i][0] && !ob) memo[i][0] = 1;
        else {
            ob = true;
            memo[i][0] = 0;
        }
    }
    ob = false;
    for (int i = 0; i < n; i++) {
        if (!obstacleGrid[0][i] && !ob) memo[0][i] = 1;
        else {
            ob = true;
            memo[0][i] = 0;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (!obstacleGrid[i][j]) {
                memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
            } else {
                memo[i][j] = 0;
            }
        }
    }
    return memo[m - 1][n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid, int type) {
    const int m = obstacleGrid.size(), n = obstacleGrid[0].size();    
    bool ob = false;
    switch (type) {
        case SOLUTION_TOP_DOWN_WITH_MEMO:
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    memo[i][j] = INT_MIN;
                    if (obstacleGrid[i][j] == 1) memo[i][j] = 0;
                }
            }
            for (int i = 0; i < m; i++) {
                if (!obstacleGrid[i][0] && !ob) memo[i][0] = 1;
                else {
                    ob = true;
                    memo[i][0] = 0;
                }
            }
            ob = false;
            for (int i = 0; i < n; i++) {
                if (!obstacleGrid[0][i] && !ob) memo[0][i] = 1;
                else {
                    ob = true;
                    memo[0][i] = 0;
                }
            }
            return unique_paths_with_obstacles_recur_with_memo(obstacleGrid, m - 1, n - 1);
            break;
        default:
            return unique_paths_with_obstacles_iter(obstacleGrid);
            break;
    }
    return -1;
}

TEST_CASE("DP with uniquePathsWithObstacles", "[.][uniquePathsWithObstacles]") {
    vector<vector<int>> obs;
    vector<int> v;
    {
        v = createVector("[0,0,0]");
        obs.push_back(v);
        v = createVector("[0,1,0]");
        obs.push_back(v);
        v = createVector("[0,0,0]");
        obs.push_back(v);

        REQUIRE(uniquePathsWithObstacles(obs, SOLUTION_BOTTOM_UP) == 2);
        REQUIRE(uniquePathsWithObstacles(obs, SOLUTION_TOP_DOWN_WITH_MEMO) == 2);
    }

    obs.clear();
    {
        v = createVector("[0,1]");
        obs.push_back(v);
        v = createVector("[0,0]");
        obs.push_back(v);
        REQUIRE(uniquePathsWithObstacles(obs, SOLUTION_BOTTOM_UP) == 1);
        REQUIRE(uniquePathsWithObstacles(obs, SOLUTION_TOP_DOWN_WITH_MEMO) == 1);
    }
}
