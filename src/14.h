class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        for (size_t i = 0; ; i++) {
            if (i >= strs[0].size()) return ret;
            char c = strs[0][i];
            for (auto s : strs) {
                if (i >= s.size()) return ret;
                if (c != s[i]) return ret;
            }
            ret.push_back(c);
        }
    }
};
