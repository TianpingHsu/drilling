#include "utils.h"

// https://leetcode.cn/problems/palindromic-substrings/ 

bool isPalindrom(const std::string& s, int i, int j) {
    while (i < j) {
        if (s[i++] != s[j--]) return false;
    }
    //cout << i << " : " << j << endl;
    return true;
}

static int memo[1024][1024];
int palindromic_substrings(string s) {
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            memo[i][j] = 0;
            if (i == j) memo[i][j] = 1;
            if (j == i + 1) memo[i][j] = (s[i] == s[j]);
        }
    }

    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = i; j < s.size(); j++) {
            if (i == j) continue;
            if (s[i] == s[j]) {
                if (j == i + 1) memo[i][j] = 1;
                else {
                    memo[i][j] = memo[i + 1][j - 1];
                }
            } else {
                memo[i][j] = false;
            }
        }
    }

    //SHOW2D(memo, s.size(), s.size());
    /*
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            if (i == j) continue;
            if (s[i] == s[j]) {
                if (j == i + 1) memo[i][j] = 1;
                else {
                    memo[i][j] = 
                        memo[i + 1][j - 1] == -1 ? 
                        (memo[i + 1][j - 1] = isPalindrom(s, i + 1, j - 1) ? 1 : 0) : memo[i + 1][j - 1];
                }
            } else {
                memo[i][j] = 0;
            }
        }
        //SHOW2D(memo, s.size(), s.size());
        //newline();
    }
    */
    int ret = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (memo[i][j] == 1) ret += 1;
        }
    }
    //SHOW2D(memo, s.size(), s.size());
    return ret;
}

int countSubstrings(string s) {
    return palindromic_substrings(s);
}

TEST_CASE("DP with countSubstrings", "[countSubstrings]") {
    std::string s;
    {
        s = "abc";
        REQUIRE(countSubstrings(s) == 3);
    }
    {
        s = "aaa";
        REQUIRE(countSubstrings(s) == 6);
    }
    {
        s = "aaaaa";
        REQUIRE(countSubstrings(s) == 15);
    }
}
