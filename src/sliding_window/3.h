
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
