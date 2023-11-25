#include "utils.h"

// https://leetcode.cn/problems/min-cost-climbing-stairs/
// n [2, 1000]
// 0 <= cost[i] <= 999

int min_cost_climbing_stairs_recur(const vector<int> &cost, int k) {
    if (k == cost.size() - 1 || k == cost.size() - 2) return cost[k];
    int a = min_cost_climbing_stairs_recur(cost, k + 1);
    int b = min_cost_climbing_stairs_recur(cost, k + 2);
    return std::min(a, b) + cost[k];
}

static int memo[1024] = {0};  // std::fill(memo, memo + sizeof(memo)/sizeof(int), INT_MAX);
int min_cost_climbing_stairs_recur_with_memo(const vector<int> &cost, int k) {
    if (k == cost.size() - 1 || k == cost.size() - 2) return cost[k];
    if (memo[k] != INT_MAX) return memo[k];
    int a = min_cost_climbing_stairs_recur_with_memo(cost, k + 1);
    int b = min_cost_climbing_stairs_recur_with_memo(cost, k + 2);
    return memo[k] = std::min(a, b) + cost[k];
}

int min_cost_climbing_stairs_iter(const vector<int> &cost) {
    std::fill(memo, memo + sizeof(memo)/sizeof(int), INT_MAX);
    memo[cost.size() - 1] = cost[cost.size() - 1];
    memo[cost.size() - 2] = cost[cost.size() - 2];

    for (int i = cost.size() - 3; i >= 0; i--) {
        int a = cost[i] + memo[i + 1];
        int b = cost[i] + memo[i + 2];
        memo[i] = std::min(a, b);
    }
    return std::min(memo[0], memo[1]);
}

int minCostClimbingStairs(const vector<int>& cost, int type) {
    switch (type) {
        case SOLUTION_TOP_DOWN:
            return std::min(min_cost_climbing_stairs_recur(cost, 0), min_cost_climbing_stairs_recur(cost, 1));
        case SOLUTION_TOP_DOWN_WITH_MEMO:
            std::fill(memo, memo + sizeof(memo)/sizeof(int), INT_MAX);
            return std::min(min_cost_climbing_stairs_recur_with_memo(cost, 0), min_cost_climbing_stairs_recur_with_memo(cost, 1));
        case SOLUTION_BOTTOM_UP:
            return min_cost_climbing_stairs_iter(cost);
        default:
            return INT_MAX;
    }
}


TEST_CASE("DP with min-cost-climbing-stairs", "[.][min-cost-climbing-stairs]") {
    std::vector<int> cost = createVector("[10,15,20]");
    REQUIRE(minCostClimbingStairs(cost, SOLUTION_BOTTOM_UP) == 15);
    REQUIRE(minCostClimbingStairs(cost, SOLUTION_TOP_DOWN_WITH_MEMO) == 15);

    cost = createVector("[1,100,1,1,1,100,1,1,100,1]");
    REQUIRE(minCostClimbingStairs(cost, SOLUTION_BOTTOM_UP) == 6);
    REQUIRE(minCostClimbingStairs(cost, SOLUTION_TOP_DOWN_WITH_MEMO) == 6);
}
