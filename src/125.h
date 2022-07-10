#include "utils.h"
class Solution {
public:
    bool isPalindrome(string s) {
        for (auto it = s.begin(); it != s.end(); ) {
            if ((*it) >= 'A' && (*it) <= 'Z') {
                *it = *it - 'A' + 'a';
            }
            if (((*it) >= 'a' && (*it) <= 'z') || (*it >= '0' && *it <= '9')) {
                it++;
                continue;
            }
            it = s.erase(it);
            if (it == s.end()) break;
        }
        size_t i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    void test() {
        CHECK(isPalindrome("OP"), false);
    }
};

