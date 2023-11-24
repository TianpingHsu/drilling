
#include "utils.h"

class Solution {
public:
#define MAX_LEN (1024 * 2 + 512)
    int memo[MAX_LEN];
    int lengthOfLIS(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) memo[i] = 1;
        int ret = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int k = i - 1; k >= 0; k--) {
                if (nums[i] > nums[k]) {
                    memo[i] = std::max(memo[i], 1 + memo[k]);
                    if (ret < memo[i]) ret = memo[i];
                }
            }
        }
        return ret;
    }
    int lis(vector<int> &nums, int i) {
        return 0;
    }
#ifdef TEST
    void test() {
        vector<int> v;
        v = createVector("[10,9,2,5,3,7,101,18]");
        CHECK(lengthOfLIS(v), 4);

        v = createVector("[0,1,0,3,2,3]");
        CHECK(lengthOfLIS(v), 4);

        v = createVector("[7,7,7,7,7,7,7]");
        CHECK(lengthOfLIS(v), 1);
    }
#endif
};
