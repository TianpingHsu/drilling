
#include "utils.h"

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    vector<vector<int>> combine(int n, int k) { 
        dfs(n, k, 1, tmp);
        return ret;
    }

    void dfs(const int n, const int k, int c, const vector<int> &current) {
        if (tmp.size() == k) {
            ret.push_back(tmp);
            return;
        } 
        for (int i = c; i <= n; i++) {
            tmp.push_back(i);
            dfs(n, k, i + 1, tmp);
            tmp.pop_back();
        }
    }
#ifdef TEST
    void test() {
        combine(4, 2);
        PRINT_MATRIX(ret);
    }
#endif
};
