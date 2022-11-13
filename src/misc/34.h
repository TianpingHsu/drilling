#include "utils.h"

class Solution {
    int lowerBound(const vector<int> &nums, int target) {
        int l = 0, r = nums.size(), m;
        // [l, r)
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] >= target) r = m;
            else l = m + 1;
        }
        return l;
    }
    int upperBound(const vector<int> &nums, int target) {
        int l = 0, r = nums.size(), m;
        // [l, r)
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] > target) r = m;
            else l = m + 1;
        }
        return l;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lowerBound(nums, target);
        int r = upperBound(nums, target);
        if (l < r) return {l, r - 1};
        else return {-1, -1};
    }
};
