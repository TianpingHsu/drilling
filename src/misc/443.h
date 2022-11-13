#include "utils.h"

class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        s.push_back(chars[0]);
        for (size_t i = 1; i < chars.size(); i++) {
            if (s.back() == chars[i]) {
                int idx = i;
                while (i < chars.size() && s.back() == chars[i]) i++;
                s += (std::to_string(i - idx + 1));
                if (i < chars.size()) s.push_back(chars[i]);
            } else {
                s.push_back(chars[i]);
            }
        }
        chars.clear();
        for (size_t i = 0; i < s.size(); i++) {
            chars.push_back(s[i]);
        }
        return s.size();
    }
    void test() {
        vector<char> v = {'E','u','e','e','e','e','e','e','e','e','e','9','9','9','9','R'};
        compress(v);
        PRINT_VEC(v);
    }
};
