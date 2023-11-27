#include "utils.h"

// https://leetcode.cn/problems/partition-equal-subset-sum/
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

static int memo[256][20280/2];
bool partition_equal_subset_sum_recur_with_memo(vector<int> &nums, int k, const int target) {
    if (memo[k][target] != -1) return memo[k][target];
    if (k == 0) return memo[k][target] = (nums[k] == target);
    if (target == nums[k]) return memo[k][target] = 1;

    bool a = false;
    if (target > nums[k]) a = partition_equal_subset_sum_recur_with_memo(nums, k - 1, target - nums[k]);
    bool b = partition_equal_subset_sum_recur_with_memo(nums, k - 1, target);
    return memo[k][target] = a || b;
}

bool partition_equal_subset_sum_iter(vector<int> &nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) sum += nums[i];
    if (sum & 1) return false;
    int target = sum / 2;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j <= target; j++) {
            memo[i][j] = -1;
        }
    }

    for (int i = 0; i <= target; i++) {
        memo[0][i] = (i == nums[0]);
    }

    for (int i = 0; i < nums.size(); i++) {
        memo[i][0] = 0;
    }

    for (int i = 1; i < nums.size(); i++) {
        for (int j = 1; j <= target; j++) {
            if (j == nums[i])  {
                memo[i][j] = true;
                break;
            }
            if (j < nums[i]) memo[i][j] = memo[i - 1][j];
            else {
                memo[i][j] = memo[i - 1][j] || memo[i - 1][j - nums[i]];
            }
        }
    }
    return memo[nums.size() - 1][target];
}

bool canPartition(vector<int>& nums, int type) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) sum += nums[i];
    if (sum & 1) return false;
    int target = sum / 2;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j <= target; j++) {
            memo[i][j] = -1;
        }
    }

    for (int i = 0; i <= target; i++) {
        memo[0][i] = (i == nums[0]);
    }

    for (int i = 0; i < nums.size(); i++) {
        memo[i][0] = 0;
    }

    if (type == 0) {
        return partition_equal_subset_sum_recur_with_memo(nums, nums.size() - 1, target);
    } else {
        return partition_equal_subset_sum_iter(nums);
    }
}

TEST_CASE("DP with canPartition", "[.][canPartition]") {
    vector<int> v;
    {
        v = createVector("[1,5,11,5]");
        REQUIRE(canPartition(v, 0) == true);
        REQUIRE(canPartition(v, 1) == true);
    }

    {
        v = createVector("[1,2,3,5]");
        REQUIRE(canPartition(v, 0) == false);
        REQUIRE(canPartition(v, 1) == false);
    }

    {
        v = createVector("[1,2,5]");
        REQUIRE(canPartition(v, 0) == false);
        REQUIRE(canPartition(v, 1) == false);
    }

    {
        v = createVector("[3,3,3,4,5]");
        REQUIRE(canPartition(v, 0) == true);
        REQUIRE(canPartition(v, 1) == true);
    }
}
