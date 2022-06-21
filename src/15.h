#include "utils.h"

class Solution {
public:
    int getSum(const vector<int> &nums, int i, int j, int k) {
        return nums[i] + nums[j] + nums[k];
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ret;
        if (nums.size() >= 3 && nums[nums.size() - 1] >= 0) {
            for (int i = 0; i < nums.size(); i++) {
                while (i != 0 && i < nums.size() && nums[i] == nums[i - 1]) i++;
                for (int j = i + 1, k = nums.size() - 1; j < nums.size() && j < k; j++) {
                    while (j != i + 1 && j < nums.size() - 1 && nums[j] == nums[j - 1]) j++;
                    while (j < k && getSum(nums, i, j, k) > 0) k--;
                    if (j < k && getSum(nums, i, j, k) == 0) {
                        ret.push_back({nums[i], nums[j], nums[k]});
                        while (k > j && nums[k] == nums[k - 1]) k--;
                    }
                }
            }
        }
        return ret;
    }
    /*
    timed out!!!
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ret;
        if (nums.size() >= 3 && nums[nums.size() - 1] >= 0) {
            for (int i = 0; i < nums.size() - 2; i++) {
                while (i != 0 && i < nums.size() && nums[i] == nums[i - 1]) i++;
                if (i < nums.size() && nums[i] > 0) break;
                for (int j = i + 1; j < nums.size() - 1; j++) {
                    while (j != i + 1 && j < nums.size() - 1 && nums[j] == nums[j - 1]) j++;
                    if (j < nums.size() && nums[i] + nums[j] > 0) break;
                    for (int k = j + 1; k < nums.size(); k++) {
                        if (getSum(nums, i, j, k) > 0) break;
                        if (getSum(nums, i, j, k) == 0) {
                            ret.push_back({nums[i], nums[j] ,nums[k]});
                            break;
                        }
                    }
                }
            }
        }
        return ret;
    }
    */
    void test() {
        // -4, -1, -1, 0, 1, 2
        //vector<int> v = {-1,0,1,2,-1,-4};
        vector<int> v = {-1, -2, 1, 2};
        //vector<int> v = {0, 0, 0, 0};
        //vector<int> v = {0, 0, 0};
        vector<vector<int>> r = threeSum(v);
        for (auto v : r) {
            for (auto x : v) {
                printf("%d ", x);
            }
            printf("\n");
        }
    }
};

