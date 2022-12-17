#include "utils.h"

class Solution {
    int lbound(vector<int> &nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] >= target) r = m;
            else l = m + 1;
        }
        return l;
    }
public:
    int search(vector<int>& nums, int target) {
        int pos = lbound(nums, target);
        if (pos == nums.size() || nums[pos] != target) return -1;
        return pos;
    }
    void test() {
        vector<int> nums = {-1, 0, 3, 5, 9, 12};
        CHECK(search(nums, 9)==4);
    }
};
