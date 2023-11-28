#include "utils.h"

// https://leetcode.cn/problems/is-subsequence/


static bool memo[128][10008];

bool is_subsequence(std::string s, std::string t) {
    if (s.empty()) return true;
    if (t.empty())  return false;
    for (int i = 0; i < s.size(); i++) {
        bool flag = false;
        for (int j = 0; j < t.size(); j++) {
            memo[i][j] = false;
            if (i == 0) {
                if (flag) memo[i][j] = true;
                if (s[i] == t[j]) {
                    flag = true;
                    memo[i][j] = true;
                }
            }
        }
    }    

    for (int i = 1; i < s.size(); i++) {
        for (int j = i; j < t.size(); j++) {
            if (s[i] == t[j]) memo[i][j] = memo[i - 1][j - 1];
            else {
                memo[i][j] = j > i ? memo[i][j - 1] : false;
            }
        }
    }

    return memo[s.size() - 1][t.size() - 1];
}

bool isSubsequence(string s, string t) {
    //return is_subsequence(s, t);

    /*
    bool ret = false;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) {
                if (i == s.size() - 1) ret = true;
                break;
            }
            if (j == t.size() - 1) return false;
        }
    }
    return ret;
    */

    int i = 0, j = 0;
    for (; i < s.size(); i++) {
        for (; j < t.size(); j++) {
            if (s[i] == t[j]) {
                if (j == t.size() - 1 && i != s.size() - 1) return false;
                if (i == s.size() - 1) return true;
                j++;
                break;
            }
            if (j == t.size() - 1 && i != s.size() - 1) return false;
        }
    }
    return s.empty() ? true : false;
}

TEST_CASE("DP with isSubsequence", "[.][isSubsequence]") {
    std::string s, t;
    /*
    {
        s = "abc";
        t = "ahbgdc";
        REQUIRE(isSubsequence(s, t) == true);
    }
    {
        s = "axc";
        t = "ahbgdc";
        REQUIRE(isSubsequence(s, t) == false);
    }
    {
        s = "";
        t = "abcd";
        REQUIRE(isSubsequence(s, t) == true);
    }
    {
        s = "acb";
        t = "ahbgdc";
        REQUIRE(isSubsequence(s, t) == false);
    }
    */
    {
        s = "aaaaaa";
        t = "bbaaaa";
        REQUIRE(isSubsequence(s, t) == false);
    }
}
