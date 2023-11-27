#include "utils.h"

// https://leetcode.cn/problems/longest-continuous-increasing-subsequence/


static int memo[2600];

int longest_continuous_increasing_subsequence(vector<int> &nums) {
    for (int i = 0; i < 2600; i++) memo[i] = 1;
    int ans = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) memo[i] = memo[i - 1] + 1;
        else memo[i] = 1;
        if (ans < memo[i]) ans = memo[i];
    }

    return ans;
}


int findLengthOfLCIS(vector<int>& nums) {
    return longest_continuous_increasing_subsequence(nums);
}


TEST_CASE("DP with findLengthOfLCIS", "[.][findLengthOfLCIS]") {
    vector<int> v;
    {
        v = createVector("[1,3,5,4,7]");
        REQUIRE(findLengthOfLCIS(v) == 3);
    }
    {
        v = createVector("[2,2,2,2,2,2]");
        REQUIRE(findLengthOfLCIS(v) == 1);
    }
}
