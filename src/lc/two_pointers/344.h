
#include "utils.h"

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            std::swap(s[i], s[j]);
            i++, j--;
        }
    }
#ifdef TEST
    void test() {
        string s = "hello";
        vector<char> v;
        for (auto c : s) v.push_back(c);
        reverseString(v);
        PRINT_VEC(v);
    }
#endif
};
