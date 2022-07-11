#include "utils.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> table;
        int ret = 0;
        queue<char> q;
        for (size_t i = 0; i < s.size(); i++) {
            if (table.find(s[i]) == table.end()) {
                table[s[i]] = i;
                if (ret < table.size()) ret = table.size();
                q.push(s[i]);
            } else {
                int old = table[s[i]];
                while (!q.empty() && q.front() != s[i]) {
                    table.erase(q.front());
                    q.pop();
                }
                if (!q.empty()) q.pop();
                q.push(s[i]);
                table[s[i]] = i;
            }
        }
        return ret;
    }
    void test() {
        CHECK(lengthOfLongestSubstring("aabaab!bb"), 3);        
    }
};

