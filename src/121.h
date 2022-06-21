class Solution {
    int *memo;
    int n;
    int MAXN = (((unsigned)-1) << 1) >> 1;
    int dp(int k, const vector<int> &profit) {
        if (k >= n) return 0;
        if (memo[k] != MAXN) return memo[k];
        vector<int> v = {profit[k] + dp(k - 1, profit), profit[k], 0};
        return memo[k] = *(std::max_element(v.begin(), v.end()));  // we use dp
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memo = new int[n];
        memo[0] = 0;
        for (size_t k = prices.size() - 1; k > 0; k--) {
            prices[k] = prices[k] - prices[k-1];
            memo[k] = MAXN;
        }
        prices[0] = 0;
        dp(n - 1, prices);
        int maxe = memo[0];
        for (int i = 1; i < n; i++) {
            if (maxe < memo[i]) maxe = memo[i];
        }
        return maxe;
    }
};

/*
我们来假设自己来购买股票。随着时间的推移，每天我们都可以选择出售股票与否。那么，假设在第 i 天，如果我们要在今天卖股票，那么我们能赚多少钱呢？
显然，如果我们真的在买卖股票，我们肯定会想：如果我是在历史最低点买的股票就好了！太好了，在题目中，我们只要用一个变量记录一个历史最低价格 minprice，我们就可以假设自己的股票是在那天买的。那么我们在第 i 天卖出股票能得到的利润就是 prices[i] - minprice。
因此，我们只需要遍历价格数组一遍，记录历史最低点，然后在每一天考虑这么一个问题：如果我是在历史最低点买进的，那么我今天卖出能赚多少钱？当考虑完所有天数之时，我们就得到了最好的答案。
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


我们需要找出给定数组中两个数字之间的最大差值（即，最大利润）。此外，第二个数字（卖出价格）必须大于第一个数字（买入价格）。
形式上，对于每组 iii 和 jjj（其中 j>ij > ij>i）我们需要找出 max(prices[j]−prices[i])\max(prices[j] - prices[i])max(prices[j]−prices[i])。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size(), ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solution/121-mai-mai-gu-piao-de-zui-jia-shi-ji-by-leetcode-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
