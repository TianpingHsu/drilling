#include "utils.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::greater<int>> q;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k) q.push(nums[i]);
            else {
                int x = q.top();
                if (x < nums[i]) {
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }
        return q.top();
    }
    void test() {

    }
};

