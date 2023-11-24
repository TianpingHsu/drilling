
#include "utils.h"

class Solution {
public:
#define MAX_LEN (20 * 1024)
    int l_max[MAX_LEN] = {0};
    int r_max[MAX_LEN] = {0};
    int trap(vector<int>& height) {
        memset(l_max, 0, sizeof(int) * MAX_LEN);
        memset(r_max, 0, sizeof(int) * MAX_LEN);
        for (int i = 1; i < height.size(); i++) {
            l_max[i] = std::max(l_max[i - 1], height[i - 1]);
        }
        for (int i = height.size() - 2; i >= 0; i--) {
            r_max[i] = std::max(r_max[i + 1], height[i + 1]);
        }
        int ret = 0;
        for (int i = 0; i < height.size(); i++) {
            ret += std::max(0, std::min(l_max[i], r_max[i]) - height[i]);
        }
        return ret;
    }

#ifdef TEST
    void test() {
        vector<int> v;
        v= createVector("[0,1,0,2,1,0,1,3,2,1,2,1]");
        CHECK(trap(v), 6);
        v = createVector("[4,2,0,3,2,5]");
        CHECK(trap(v), 9);
    }
#endif
};
