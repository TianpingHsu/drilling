#include "utils.h"

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            size_t maxLen = 0;
            map<char, size_t> win;
            for (size_t i = 0, j = 0; j < s.size(); j++) {
                if (win.find(s[j]) == win.end()) {
                    win[s[j]] = j;
                    if (j == s.size() - 1) return maxLen = (maxLen < win.size()) ?  win.size() : maxLen;
                } else {
                    if (maxLen < j - i) maxLen = j - i;
                    size_t tmp = win[s[j]];
                    for (size_t k = i; k <= tmp; k++) {
                        win.erase(s[k]);  // we will delete `s[tmp]`, which has same value of `s[j]`
                    }
                    win[s[j]] = j;  // insert s[j]
                    i = tmp + 1;
                }
            }
            return maxLen;
        }

        void test() {
            CHECK_INT(lengthOfLongestSubstring("au"), 2);
            CHECK_INT(lengthOfLongestSubstring("bbb"), 1);
            CHECK_INT(lengthOfLongestSubstring("aab"), 2);
        }
};
