
#include "utils.h"

class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ret;
        for (int i = 0; i < chars.size(); i++) {
            ret.push_back(chars[i]);
            int j = i + 1;
            while (j < chars.size() && chars[i] == chars[j]) j++;
            int count = j - i;
            if (count > 1) {
                std::string s = std::to_string(count);
                for (auto item : s) ret.push_back(item);
            }
            i = j - 1;
        }
        chars = ret;
        return ret.size();
    }
#ifdef TEST
    void test() {
        vector<char> chars;
        std::string s;
        {
            chars.clear(), s.clear();
            s = "a";
            for (auto c : s) chars.push_back(c);
            OUT(compress(chars));
            PRINT_VEC(chars);
        }
    }
#endif
};
