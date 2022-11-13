#include "utils.h"

class Solution {
    int memo[1024 * 3];
    int dp(const vector<int> &nums, int idx) {
        if (memo[idx] != -1) return memo[idx];
        int current = 1;
        for (int i = idx - 1; i >= 0; i--) {
            memo[i] = dp(nums, i);
            if (nums[idx] > nums[i] && current < memo[i] + 1) 
                current = memo[i] + 1;
        }
        memo[idx] = current;
        return memo[idx];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        memo[0] = 1;
        dp(nums, nums.size() - 1);
        int ret = *(std::max_element(memo, memo + nums.size()));
        return ret;
    }

    void test() {
        vector<int> v = { 10,9,2,5,3,7,101,18 };
        CHECK(lengthOfLIS(v), 4);
    }
};
