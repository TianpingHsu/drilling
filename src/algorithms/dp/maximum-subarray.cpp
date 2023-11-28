#include "utils.h"

// https://leetcode.cn/problems/maximum-subarray/

static int memo[10008];
int maximum_subarray(vector<int> &nums) {
    memo[0] = nums[0];

    int ans = memo[0];
    for (int i = 1; i < nums.size(); i++) {
        memo[i] = std::max(memo[i - 1] + nums[i], nums[i]);
        if (ans < memo[i]) ans = memo[i];
    }
    return ans;
}

int maxSubArray(vector<int>& nums) {
    return maximum_subarray(nums);
}

TEST_CASE("DP with maxSubArray", "[.][maxSubarray]") {
    vector<int> v;
    {
        v = createVector("[-2,1,-3,4,-1,2,1,-5,4");
        REQUIRE(maxSubArray(v) == 6);
    }
    {
        v = createVector("[5,4,-1,7,8]");
        REQUIRE(maxSubArray(v) == 23);
    }
    {
        v = createVector("[1]");
        REQUIRE(maxSubArray(v) == 1);
    }
}
