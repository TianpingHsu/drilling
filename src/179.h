#include "utils.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ss;
        bool all0 = true;
        for (auto x : nums) {
            ss.push_back(std::to_string(x));
            if (x != 0) all0 = false;
        }
        if (all0) return "0";
        std::sort(ss.begin(), ss.end(), [](const string &s1, const string &s2) {
            if (s1.size() == s2.size()) return s1 > s2;
            return s1 + s2 > s2 + s1;
        });
        string ret;
        for (auto x : ss) ret += x;
        return ret;
    }
};
