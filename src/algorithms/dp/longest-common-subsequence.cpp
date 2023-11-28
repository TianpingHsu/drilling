#include "utils.h"

// https://leetcode.cn/problems/longest-common-subsequence/

static int memo[1024][1024];
int longest_common_subsequence(string s1, string s2) {
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            memo[i][j] = 0;
        }
    }
    bool flag = false;
    for (int i = 0; i < s1.size(); i++) {
        if (flag) {
            memo[i][0] = 1;
            continue;
        }
        if (s1[i] == s2[0]) {
            flag = true;
            memo[i][0] = 1;
        }
    }
    flag = false;
    for (int i = 0; i < s2.size(); i++) {
        if (flag) {
            memo[0][i] = 1;
            continue;
        }
        if (s1[0] == s2[i]) {
            memo[0][i] = 1;
            flag = true;
        }
    }

    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) memo[i][j] = memo[i - 1][j - 1] + 1;
            else {
                memo[i][j] = std::max({memo[i - 1][j], memo[i][j - 1], memo[i - 1][j - 1]});
            }
        }
    }
    return memo[s1.size() - 1][s2.size() - 1];
}

int longestCommonSubsequence(string text1, string text2) {
    return longest_common_subsequence(text1, text2);
}

TEST_CASE("DP with longestCommonSubsequence", "[.][longestCommonSubsequence]") {
    std::string s1, s2;
    {
        s1 = "abcde";
        s2 = "ace";
        REQUIRE(longestCommonSubsequence(s1, s2) == 3);
    }
    {
        s1 = "abc";
        s2 = "abc";
        REQUIRE(longestCommonSubsequence(s1, s2) == 3);
    }
    {
        s1 = "a";
        s2 = "b";
        REQUIRE(longestCommonSubsequence(s1, s2) == 0);
    }
    {
        s1 = "abc";
        s2 = "def";
        REQUIRE(longestCommonSubsequence(s1, s2) == 0);
    }
}
