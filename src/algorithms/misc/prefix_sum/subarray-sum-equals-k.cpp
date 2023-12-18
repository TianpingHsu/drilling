#include "utils.h"

// https://leetcode.cn/problems/subarray-sum-equals-k/

int subarray_sum_equals_k(vector<int>& nums, int k) {
    map<int, int> table = {{0, 1}};  // 
    int sum = 0, ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (table.find(sum - k) != table.end()) ans ++;
        table[sum] ++;
    }
    return ans;
}

int subarraySum(vector<int>& nums, int k) {
    return subarray_sum_equals_k(nums,k );
}

TEST_CASE("prefix sum with subarraySum", "[.][subarraySum]") {
    vector<int> v;
    int k = 0;
    {
        v = createVector("[1,1,1]");
        k = 2;
        REQUIRE(subarraySum(v, k) == 2);
    }
    {
        v = createVector("[1,2,3]");
        k = 3;
        REQUIRE(subarraySum(v, k) == 2);
    }
}
