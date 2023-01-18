
#include "utils.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (int i = 0; i < prices.size(); i++) {
            int j = i + 1;
            while (j < prices.size()) {
                if (prices[j] >= prices[i]) {  // climb
                    ret += prices[j] - prices[i];
                    j++, i++;
                } else {
                    break;
                }
            }
        }
        return ret;
    }
#ifdef TEST
    void test() {
        vector<int> v;
        v = createVector("[7,1,5,3,6,4]");
        CHECK(maxProfit(v), 7);

        v = createVector("[1,2,3,4,5]");
        CHECK(maxProfit(v), 4);
    }
#endif
};

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/solutions/38498/tan-xin-suan-fa-by-liweiwei1419-2/
