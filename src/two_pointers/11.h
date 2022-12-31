
#include "utils.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int max_area = 0;
        while (i < j) {
            int tmp = std::min(height[i], height[j]) * (j - i);
            max_area = max_area < tmp ? tmp : max_area;
            if (height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }
        return max_area;
    }
#ifdef TEST
    void test() {
        vector<int> v = createVector("[1,8,6,2,5,4,8,3,7]");
        CHECK(maxArea(v), 49);
        v = createVector("[1,1]");
        CHECK(maxArea(v), 1);
    }
#endif
};

// https://leetcode.cn/problems/container-with-most-water/solutions/207215/sheng-zui-duo-shui-de-rong-qi-by-leetcode-solution/
