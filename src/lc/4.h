#include "utils.h"

class Solution {

    // v1[l, r), v2[p, q), k: 1, 2, 3...
    int getKthElement(const vector<int> &v1, const vector<int> &v2, int l, int r, int p, int q, int k) {
        if (l >= r) return v2[p + k - 1];
        if (p >= q) return v1[l + k - 1];
        if (k == 1) return std::min(v1[l], v2[p]);
        int m = k/2 - 1;
        //int x = v1[(m >= r) ? r - 1 : m], y = v2[(m >= q) ? q - 1 : m];
        int m1 = (l + m >= r) ? r - 1 : l + m, m2 = (p + m >= q) ? q - 1 : p + m;
        if (v1[m1] <= v2[m2]) {
            return getKthElement(v1, v2, m1 + 1, r, p, q, k - (m1 - l + 1));
        } else {
            return getKthElement(v1, v2, l, r, m2 + 1, q, k - (m2 - p + 1));
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = nums1.size(), p = 0, q = nums2.size();        
        int total_len = (r - l) + (q - p);
        if (total_len % 2 == 1) {
            int k = (total_len + 1) / 2;
            return getKthElement(nums1, nums2, l, r, p, q, k);
        } else {
            int x = getKthElement(nums1, nums2, l, r, p, q, total_len / 2);
            int y = getKthElement(nums1, nums2, l, r, p, q, total_len / 2 + 1);
            return (x + y) / 2.0;
        }
    }
    void test() {
        {
            /*
            vector<int> 
                nums1 = createVector("[1,3]"),
                nums2 = createVector("[2, 4]");
            OUT(findMedianSortedArrays(nums1, nums2));
            */
        }
        {
            vector<int> 
                nums1 = createVector("[2]"),
                nums2 = createVector("[1, 3, 4]");
            OUT(findMedianSortedArrays(nums1, nums2));
        }
    }
};
