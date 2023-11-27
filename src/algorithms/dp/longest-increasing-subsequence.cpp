#include "utils.h"

// https://leetcode.cn/problems/longest-increasing-subsequence/

static int memo[2600];

/*
 * memo[i] = memo[ i - 1 ] if nums[i] <= nums[i - 1] else memo[i - 1] + 1
 */

int longest_increasing_subsequence(vector<int>& nums) {
    //show(nums);
    for (int i = 0; i < 2600; i++) memo[i] = 1;
    int ans = 1;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] > nums[j]) {
                if (memo[i] < memo[j] + 1) memo[i] = memo[j] + 1;
            }
        }
        //SHOW1D(memo, nums.size());
        if (ans < memo[i]) ans = memo[i];
    }

    return ans;
}

int lengthOfLIS(vector<int>& nums) {
    return longest_increasing_subsequence(nums);
}

TEST_CASE("DP with lengthOfLIS", "[.][lengthOfLIS]") {
    vector<int> v;
    {
        v = createVector("[10,9,2,5,3,7,101,18]");
        REQUIRE(lengthOfLIS(v) == 4);
    }

    {
        v = createVector("[0,1,0,3,2,3]");
        REQUIRE(lengthOfLIS(v) == 4);
    }

    {
        v = createVector("[7,7,7,7,7,7,7]");
        REQUIRE(lengthOfLIS(v) == 1);
    }
    {
        v = createVector("[1]");
        REQUIRE(lengthOfLIS(v) == 1);
    }
    {
        v = createVector("[4,10,4,3,8,9]");
        REQUIRE(lengthOfLIS(v) == 3);
    }
    {
        v = createVector("[1,3,6,7,9,4,10,5,6]");
        REQUIRE(lengthOfLIS(v) == 6);
    }
}
