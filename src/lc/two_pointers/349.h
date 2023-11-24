
#include "utils.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> ret;
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] == nums2[j]) {
                ret.push_back(nums1[i]);
                i++, j++;
                while (i < nums1.size() && (nums1[i] == nums1[i - 1])) i++;
                while (j < nums2.size() && (nums2[j] == nums2[j - 1])) j++;
                if ((i >= nums1.size()) || (j >= nums2.size())) break;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }
        return ret;
    }
#ifdef TEST
    void test() {
        vector<int> n1, n2;
        n1 = createVector("[1,2,2,1]");
        n2 = createVector("[2,2]");
        PRINT_VEC(intersection(n1, n2));
    }
#endif
};
