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
/*

#include "utils.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        int ret = 0;
        int hash[256];
        memset(hash, -1, sizeof(hash));
        int i = 0, j = 1;
        hash[s[0]] = 0;
        for (;i < s.size(), j < s.size(); ) {
            while (hash[s[j]] == -1 && j < s.size()) {
               hash[s[j]] = j;
               j++;
            }
            if (ret < j - i) ret = j - i;
            int k = i;
            i = hash[s[j]] + 1;
            for (; k <= hash[s[j]]; k++) hash[s[k]] = -1;
            hash[s[j]] = j;
            j++;
        }
        return ret;
    }

    void test() {
        CHECK(lengthOfLongestSubstring("ababcabcbbcabcbb"), 3);
    }
};

// https://leetcode.cn/problems/longest-substring-without-repeating-characters/solutions/3982/hua-dong-chuang-kou-by-powcai/
*/
