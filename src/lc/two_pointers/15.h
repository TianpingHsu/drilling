
#include "utils.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i != 0) {
                while (i < nums.size() - 2 && (nums[i] == nums[i - 1])) {
                    i++;
                }
            }
            for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
                if (j != i + 1) {
                    while (j < k && (nums[j] == nums[j - 1])) {
                        j++;
                    }
                }
                while ((nums[i] + nums[j] + nums[k] > 0) && j < k) {
                    k--;
                }
                if (j < k && (nums[i] + nums[j] + nums[k] == 0)) {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    do {
                        k--;
                    } while (j < k && nums[k] == nums[k + 1]);
                }
            }
        }
        return ret;
    }
#ifdef TEST
    void test() {
        vector<int> v = createVector("[-1,0,1,2,-1,-4]");
        vector<vector<int>> ans = {{-1, -1, 2}, {-1, 0, 1}};
        vector<vector<int>> ret = threeSum(v);
        OUT((ans == ret));
        v = createVector("[0,0,0]");
        ret = threeSum(v);
        ans = {{0, 0, 0}};
        OUT((ans == ret));
        v = createVector("[1,-1,-1,0]");
        ans = {{-1, 0, 1}};
        ret = threeSum(v);
        OUT((ans == ret));
    }
#endif
};
