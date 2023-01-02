
#include "utils.h"

class Solution {
public:
    void moveForward(vector<int>& nums, int k) {
        while (k < nums.size() - 1) {
            nums[k] = nums[k + 1];
            k++;
        }
    }
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - count; i++) {
            while (nums[i] == 0 && count < nums.size()) {
                count++;
                moveForward(nums, i);
                nums[nums.size() - 1] = -1;
            } 
        }
        int i = nums.size() - 1;
        while (count--) {
            nums[i--] = 0;
        }
    }
#ifdef TEST
    void test() {
        vector<int> v;
        v = createVector("[0,1,0,3,12]");
        moveZeroes(v);
        PRINT_VEC(v);

        v = createVector("[0]");
        moveZeroes(v);
        PRINT_VEC(v);

        v = createVector("[0,1,0]");
        moveZeroes(v);
        PRINT_VEC(v);

        v = createVector("[0,0,1]");
        moveZeroes(v);
        PRINT_VEC(v);
    }
#endif
};
