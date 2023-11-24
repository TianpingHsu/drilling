class Solution {
    vector<int> tmp;
    vector<vector<int>> ret;
    void dfs(vector<int> &nums, int idx) {
        if (idx == nums.size()) {
            ret.push_back(tmp);
            return ;
        }
        dfs(nums, idx+1);
        tmp.push_back(nums[idx]);
        dfs(nums, idx + 1);
        tmp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }
};
/*
#include "utils.h"

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ret;
    vector<vector<int>> subsets(vector<int>& nums) {
        powerSet(nums, 0);
        return ret;
    }
    void powerSet(vector<int> &nums, int k) {
        if (k == nums.size()) {
            ret.push_back(tmp);
            return;
        }
        tmp.push_back(nums[k]);
        powerSet(nums, k + 1);
        tmp.pop_back();
        powerSet(nums, k + 1);
    }
#ifdef TEST
    void test() {
        vector<int> v;
        v = createVector("[1,2,3]");
        subsets(v);
        PRINT_MATRIX(ret);

        v = createVector("[1]");
        subsets(v);
        PRINT_MATRIX(ret);
    }
#endif
};
*/
