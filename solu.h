#ifndef __SOLU_H__
#define __SOLU_H__
#include "utils.h"

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int sum = 0;
            int maxSum = 0;
            int maxElement = nums[0];
            for (size_t i = 0; i < nums.size(); i++) {
                if (maxElement < nums[i]) maxElement = nums[i];
                sum += nums[i];
                if (sum > maxSum) maxSum = sum;
                if (sum < 0) sum = 0;
            }
            return maxElement < 0 ? maxElement : maxSum;
        }
        void test() {

        }
};

#endif
