
#include "utils.h"

class Solution {
public:
    map<int, bool> used;
    vector<vector<int>> ret;
    vector<int> tmp;
    vector<vector<int>> permute(vector<int>& nums) {
        for (auto x : nums) used[x] = false;
        permutation(nums);
        return ret;
    }

    void permutation(vector<int>& nums) {
        if (tmp.size() == nums.size()) {
            ret.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[nums[i]]) {
                tmp.push_back(nums[i]);
                used[nums[i]] = true;
                permutation(nums);
                tmp.pop_back();
                used[nums[i]] = false;
            }
        }
    }
#ifdef TEST
    void test() {
        vector<int> v;
        v = createVector("[1,2,3]");
        permute(v);
        PRINT_MATRIX(ret);
    }
#endif
};
