class Solution {
    map<size_t, bool> table;
    vector<vector<int>> ret;
    vector<int> v;
    void allPermutation(vector<int> &nums) {
        for (auto x : nums) {
            if (!table[x]) {
                table[x] = true;
                v.push_back(x);
                if (v.size() == nums.size()) ret.push_back(v);
                allPermutation(nums);
                v.pop_back();
                table[x] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        allPermutation(nums);
        return ret;
    }
};

/*
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
*/
