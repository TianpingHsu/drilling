#include "utils.h"

// https://leetcode.cn/problems/longest-palindromic-subsequence/

static int memo[1024][1024];
int longest_palindromic_subsequence(string s) {
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            memo[i][j] = 0;
            if (i == j) memo[i][j] = 1;
        }
    } 

    //for (int i = 0; i < s.size(); i++) {
        //for (int j = i + 1; j < s.size(); j++) {
    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] == s[j]) {
                if (j == i + 1) memo[i][j] = 2;
                else memo[i][j] = memo[i + 1][j - 1] + 2;
            } else {
                memo[i][j] = std::max(memo[i][j - 1], memo[i + 1][j]);
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (ans < memo[i][j]) ans = memo[i][j];
        }
    }
    return ans;;
}

int longestPalindromeSubseq(string s) {
    return longest_palindromic_subsequence(s);
}

TEST_CASE("DP with longestPalindromeSubseq", "[longestPalindromeSubseq]") {
    std::string s;
    {
        s = "bbbab";
        REQUIRE(longestPalindromeSubseq(s) == 4);
    }
    {
        s = "cbbd";
        REQUIRE(longestPalindromeSubseq(s) == 2);
    }
}

