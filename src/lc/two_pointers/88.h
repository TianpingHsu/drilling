
#include "utils.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1, i = m - 1, j = n - 1;
        OUT(i);
        OUT(j);
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while (i >= 0) nums1[k--] = nums1[i--];
        while (j >= 0) nums1[k--] = nums2[j--];
    }

#ifdef TEST
    void test() {
        vector<int> nums1, nums2;
        int m, n;
        {
            nums1 = createVector("[1,2,3,0,0,0]");
            nums2 = createVector("[2,5,6]");
            m = 3;
            n = 3;
            //merge(nums1, m, nums2, n);
            //PRINT_VEC(nums1);
        }
        {
            nums1 = createVector("[0]");
            nums2 = createVector("[1]");
            m = 0;
            n = 1;
            merge(nums1, m, nums2, n);
            PRINT_VEC(nums1);
        }
    }
#endif
};
