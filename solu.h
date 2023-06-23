
#include "inc/utils.h"
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
#ifdef TEST
    void test() {
        vector<int> nums = {-1, 1, 1};
        CHECK(majorityElement(nums), 1);
    }
#endif
};

