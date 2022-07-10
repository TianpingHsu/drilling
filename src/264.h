#include "utils.h"
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> ret;
        priority_queue<long long, vector<long long>, std::greater<long long>> q;
        q.push(1);
        while (!q.empty()) {
            while (ret.find(q.top()) != ret.end()) q.pop();
            long long x = q.top();
            q.pop();
            ret.insert(x);
            if (ret.size() == n) return x;
            const long long factors[] = {2, 3, 5};
            for (auto f : factors) {
                q.push(f * x);
            }
        }
        return 1;
    }
    void test() {
        cout << nthUglyNumber(10) << endl;
    }
};

/*
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; i++) {
            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);
            if (dp[i] == num2) {
                p2++;
            }
            if (dp[i] == num3) {
                p3++;
            }
            if (dp[i] == num5) {
                p5++;
            }
        }
        return dp[n];
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/ugly-number-ii/solution/chou-shu-ii-by-leetcode-solution-uoqd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
