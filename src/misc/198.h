#include "utils.h"

class Solution {
    static const int MAX_N = 128;
    int memo[MAX_N];
    int dfs(const vector<int> &nums, int k) {
        if (memo[k] != -1) return memo[k];
        int tmp = 0;
        for (int i = k - 2; i >= 0; i--) {
            int x = dfs(nums, i) + nums[k];
            if (tmp < x) tmp = x;
        }
        return memo[k] = tmp;
    }
public:
    int rob(vector<int>&& nums) {
        if (nums.size() == 1) return nums[0];
        memset(memo, -1, sizeof(memo));
        memo[0] = nums[0];
        memo[1] = nums[1];
        int ret = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int tmp = dfs(nums, i);
            if (tmp > ret) ret = tmp;
        }
        return ret;
    }
    void test() {
        //CHECK(rob(createVector("[1,2,3,1]")), 4);
        CHECK(rob(createVector("[2,7,9,3,1]")), 12);
    }
};
