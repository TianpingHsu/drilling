#include "utils.h"

// https://leetcode.cn/problems/delete-operation-for-two-strings/

static int memo[512][512];

int delete_operation_for_two_strings(string w1, string w2) {
    for (int i = 0; i <= w1.size(); i++) {
        for (int j = 0; j <= w2.size(); j++) {
            memo[i][j] = INT_MAX;
        }
    }
    memo[0][0] = 0;
    for (int i = 1; i <= w1.size(); i++) memo[i][0] = i;
    for (int i = 1; i <= w2.size(); i++) memo[0][i] = i;
    for (int i = 1, flag = false; i <= w1.size(); i++) {
        if (flag) memo[i][1] = i - 1;
        else {
            if (w1[i - 1] == w2[0]) {
                flag = true;
                memo[i][1] = i - 1;
            } else {
                memo[i][1] = i + 1;
            }
        }
    }
    for (int i = 1, flag = false; i <= w2.size(); i++) {
        if (flag) memo[1][i] = i - 1;
        else {
            if (w1[0] == w2[i - 1]) {
                flag = true;
                memo[1][i] = i - 1;
            } else {
                memo[1][i] = i + 1;
            }
        }
    }
    //SHOW2D(memo, w1.size() + 1, w2.size() + 1);
    //newline();
    for (int i = 1; i <= w1.size(); i++) {
        for (int j = 1; j <= w2.size(); j++) {
            if (w1[i - 1] == w2[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1];
            } else {
                memo[i][j] = std::min({memo[i-1][j-1] + 2, memo[i-1][j] + 1, memo[i][j - 1] + 1});
            }
        }
        //SHOW2D(memo, w1.size() + 1, w2.size() + 1);
        //newline();
    }
    return memo[w1.size()][w2.size()];
}

int minDistance(string word1, string word2) {
    return delete_operation_for_two_strings(word1, word2);
}

TEST_CASE("DP with minDistance", "[.][minDistance]") {
    string w1, w2;
    {
        w1 = "sea";
        w2 = "eat";
        REQUIRE(minDistance(w1, w2) == 2);
    }
    {
        w1 = "leetcode";
        w2 = "etco";
        REQUIRE(minDistance(w1, w2) == 4);
    }
}
