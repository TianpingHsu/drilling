
#include "utils.h"

class Solution {
public:
    bool isVowel(const char c) {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') 
            || (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U');

    }
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (!isVowel(s[i]) && i < j) i++;
            while (!isVowel(s[j]) && i < j) j--;
            if (i < j) {
                std::swap(s[i], s[j]);
                i++, j--;
            }
        }
        return s;
    }
#ifdef TEST
    void test() {
        CHECK(reverseVowels("hello"), "holle");
        CHECK(reverseVowels("leetcode"), "leotcede");
        CHECK(reverseVowels("aA"), "Aa");
    }
#endif
};
