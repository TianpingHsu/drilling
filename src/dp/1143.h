
#include "utils.h"

class Solution {
public:
#define MAX_LEN 1024
    int memo[MAX_LEN][MAX_LEN];
    int longestCommonSubsequence(string text1, string text2) {
        memset(memo[0], -1, MAX_LEN * MAX_LEN * sizeof(int));
        int max_len = std::max(text1.size(), text2.size());
        for (int i = 0; i <= max_len; i++) {
            memo[i][0] = memo[0][i] = 0;
        }
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    memo[i][j] = 1 + memo[i - 1][j - 1];
                } else {
                    memo[i][j] = std::max(memo[i][j - 1], memo[i - 1][j]);
                }
            }
        }
        return memo[text1.size()][text2.size()];
        //return lcs(text1, text1.size(), text2, text2.size());    
    }

    // recursion version
    int lcs(const string text1, int i, const string text2, int j) {
        if (memo[i][j] != -1) return memo[i][j];
        if (text1[i - 1] == text2[j - 1]) {
            return memo[i][j] = 1 + lcs(text1, i - 1, text2, j - 1);
        } else {
            return memo[i][j] = std::max(lcs(text1, i, text2, j - 1), lcs(text1, i - 1, text2, j));
        }
    }

#ifdef TEST
    void test() {
        std::string s1, s2;
        s1 = "abcde";
        s2 = "ace";
        CHECK(longestCommonSubsequence(s1, s2), 3);

        s1 = "abc";
        s2 = "abc";
        CHECK(longestCommonSubsequence(s1, s2), 3);

        s1 = "abc";
        s2 = "def";
        CHECK(longestCommonSubsequence(s1, s2), 0);
    }
#endif
};
