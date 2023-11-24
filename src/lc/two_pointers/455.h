
#include "utils.h"
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int count = 0;
        for (int i = 0, j = 0; i < g.size() && j < s.size(); i++, j++) {
            while (j < s.size() && s[j] < g[i]) j++;
            if (j == s.size()) break;
            count++;
        }
        return count;
    }
#ifdef TEST
    void test() {
        vector<int> g, s;
        g = createVector("[1,2,3]");
        s = createVector("[1,1]");
        CHECK(findContentChildren(g, s), 1);

        g = createVector("[1,2]");
        s = createVector("[1,2,3]");
        CHECK(findContentChildren(g, s), 2);

        g = createVector("[10,9,8,7]");
        s = createVector("[5,6,7,8]");
        CHECK(findContentChildren(g, s), 2);
    }
#endif
};
