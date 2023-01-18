
#include "utils.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int *l_min = new int[prices.size()], 
            *r_max = new int[prices.size()];
        l_min[0] = prices[0], r_max[prices.size() - 1] = prices.back();
        for (int i = 1; i < prices.size(); i++) {
            l_min[i] = std::min(prices[i], l_min[i - 1]);
        }
        for (int j = prices.size() - 2; j >= 0; j--) {
            r_max[j] = std::max(prices[j], r_max[j + 1]);
        }
        int ret = 0;
        for (int i = 0; i < prices.size(); i++) {
            ret = std::max(ret, r_max[i] - l_min[i]);
        }
        delete[] l_min;
        delete[] r_max;
        return ret;
    }
#ifdef TEST
    void test() {
        vector<int> v;
        v = createVector("[7,1,5,3,6,4]");
        CHECK(maxProfit(v), 5);

        v = createVector("[7,6,4,3,1]");
        CHECK(maxProfit(v), 0);
    }
#endif
};
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solutions/136684/121-mai-mai-gu-piao-de-zui-jia-shi-ji-by-leetcode-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
