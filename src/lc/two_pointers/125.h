
#include "utils.h"
class Solution {
public:
    bool isAlphaBeta(char &c) {
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
            return true;
        }
        if (c >= '0' && c <= '9') return true;
        return false;
    }
    bool isPalindrome(string s) {
        string ret;
        for (auto c : s) {
            if (isAlphaBeta(c)) ret.push_back(c);
        }
        s.clear();
        s = ret;
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
#ifdef TEST
    void test() {
        CHECK(isPalindrome("A man, a plan, a canal: Panama"), true);
        CHECK(isPalindrome("race a car"), false);
    }
#endif
};
