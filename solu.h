#include "utils.h"

class Solution {
    static const int MAXN = 512;
    int memo[MAXN][MAXN];
    /*
    memo[i][j]: min distance of str1 and str2
    we have formular:
    memo[i][j] = min{
        memo[i - 1][j - 1],  // if str1[i] == str2[j]
        memo[i][j - 1] + 1,  // if str1[i] != str2[j]
        memo[i - 1][j] + 1,  // if str1[i] != str2[j]
        memo[i - 1][j - 1] + 1,  // if str1[i1] != str2[j]
    }
    */
    int dp(const string &w1, const string &w2, int i, int j) {
        if (memo[i][j] != -1) return memo[i][j];
        if (w1[i] == w2[j]) return memo[i][j] = dp(w1, w2, i - 1, j - 1);
        else {
            vector<int> v = {
                dp(w1, w2, i, j - 1) + 1,
                dp(w1, w2, i - 1, j) + 1,
                dp(w1, w2, i - 1, j - 1) + 1
            };
            return memo[i][j] = *(std::min_element(v.begin(), v.end()));
        }
    }
public:
    int minDistance(string word1, string word2) {
        for (size_t i = 0; i < MAXN; i++) {
            for (size_t j = 0; j < MAXN; j++) {
                memo[i][j] = -1;
                if (i == 0) memo[i][j] = j;
                if (j == 0) memo[i][j] = i;
            }
        }
        return dp(word1, word2, word1.size() - 1, word2.size() - 1);
    }

    void test() {
        //CHECK_INT(minDistance("intention", "execution"), 5);
        //CHECK_INT(minDistance("horse", "ros"), 3);
        //CHECK_INT(minDistance("", ""), 0);
        CHECK_INT(minDistance("ros", "horse"), 3);
    }
};
