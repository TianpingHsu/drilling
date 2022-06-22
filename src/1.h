#include "utils.h"
class Solution {
    int cur = 0;
    int search(int target, const vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (target == nums[i] && i != cur) return i;
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = 0;
        for (; i < nums.size(); i++) {
            cur = i;
            if ((j = search(target - nums[i], nums)) != -1) {
                break;
            }
        }
        return {i, j};
    }
    void test() {

    }
};
