
#include "utils.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = -1, fast = 0;
        while (fast < nums.size()) {
            int k = fast + 1;
            while (k < nums.size() && nums[k] == nums[fast]) k++;
            nums[++slow] = nums[fast];
            fast = k;
        }
        return slow + 1;
    }
#ifdef TEST
    void test() {
        vector<int> v;
        v = createVector("[1,1,2]");
        CHECK(removeDuplicates(v), 2);
        PRINT_VEC(v);

        v = createVector("[0,0,1,1,1,2,2,3,3,4]");
        CHECK(removeDuplicates(v), 5);
        PRINT_VEC(v);
    }
#endif
};
