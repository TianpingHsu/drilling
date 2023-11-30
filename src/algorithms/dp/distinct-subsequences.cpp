#include "utils.h"

// https://leetcode.cn/problems/distinct-subsequences/

static int memo[1024][1024];
const static int MOD = 1000000000 + 7;
int distinct_subsequences(string s, string t) {
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) {
            memo[i][j] = 0;
        }
    }
    for (int i = 0, x = 0; i < s.size(); i++) {
        if (s[i] == t[0]) ++x;
        memo[i][0] = x;
    }
    //SHOW2D(memo, s.size(), t.size());
    //newline();

    /*
     * memo[i][j] = 
     * {
     *  memo[i - 1][j - 1] + memo[i - 1][j] if (s[i] == t[j])
     *  memo[i - 1][j]
     * }
     */
    for (int j = 1; j < t.size(); j++) {
        for (int i = j; i < s.size(); i++) {
            if (s[i] == t[j]) {
                memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j]) % MOD;
            } else {
                memo[i][j] = memo[i - 1][j];
            }
        }
        //SHOW2D(memo, s.size(), t.size());
        //newline();
    }
    return memo[s.size() - 1][t.size() - 1];
}

int numDistinct(string s, string t) {
    return distinct_subsequences(s, t);
}

TEST_CASE("DP with numDistinct", "[.][numDistinct]") {
    std::string s, t;
    {
        s = "rabbbit";
        t = "rabbit";
        REQUIRE(numDistinct(s, t) == 3);
    }
    {
        s = "babgbag";
        t = "bag";
        REQUIRE(numDistinct(s, t) == 5);
    }
    {
        s = "aabb";
        t = "ab";
        REQUIRE(numDistinct(s, t) == 4);
    }
}
