

#include "inc/utils.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        priority_queue<int> q;
        vector<int> ret;
        int i = 0;
        while (i < k - 1) {
            s.insert(nums[i]);
            i++;
        }
        for (; i < nums.size(); i++) {
            s.insert(nums[i]);
            show(s);
            ret.push_back(*s.rbegin());
            s.erase(s.find(nums[i - k + 1]));
        }
#ifdef TEST
        PRINT_VEC(ret);
#endif
        return ret;
    }

#ifdef TEST
    void test() {
#if 0
        {
            vector<int> v = createVector("[1,3,-1,-3,5,3,6,7]");
            vector<int> ans{3,3,5,5,6,7};
            CHECK((maxSlidingWindow(v, 3) == ans), true);
        }
#endif
        {
            vector<int> v = createVector("[-7,-8,7,5,7,1,6,0]");
            show(v);
            vector<int> ans{7,7,7,7,7};
            CHECK((maxSlidingWindow(v, 4) == ans), true);
        }

    }
#endif

};
