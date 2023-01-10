
#include "utils.h"

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    map<int, bool> used;
    vector<vector<int>> combine(int n, int k) { 
        for (int i = 1; i <= n; i++) {
            used[i] = false;
        }
        dfs(n, k, 1);
        return ret;
    }

    void dfs(const int n, const int k, int c) {
        if (tmp.size() + (n - c + 1) < k) {
            return;
        }
        if (tmp.size() == k) {
            ret.push_back(tmp);
            return;
        } 
        tmp.push_back(c);
        dfs(n, k, c + 1);
        tmp.pop_back();
        dfs(n, k, c + 1);
    }
#ifdef TEST
    void test() {
        combine(4, 2);
        PRINT_MATRIX(ret);
    }
#endif
};
