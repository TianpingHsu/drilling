
#include "utils.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        if (s.size() > t.size()) return false;
        int i = s.size() - 1, j = t.size() - 1;
        while (i >= 0) {
            while (j >= 0 && t[j] != s[i]) j--;
            if (j < 0) {
                if (i >= 0) return false;
            } else {
                if (t[j] == s[i]) {
                    j--;
                }
            }
            i--;
        }
        return true;
    }
#ifdef TEST
    void test() {
        CHECK(isSubsequence("abc", "ahbgdc"), true);
        CHECK(isSubsequence("axc", "ahbgdc"), false);
        CHECK(isSubsequence("", "ahbgdc"), true);
        CHECK(isSubsequence("", ""), true);
        CHECK(isSubsequence("a", ""), false);
        CHECK(isSubsequence("a", "b"), false);
        CHECK(isSubsequence("aaa", "bba"), false);
    }
#endif
};
