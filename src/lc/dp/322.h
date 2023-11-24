
#include "utils.h"

class Solution {
public:
#define MAX_LEN 16
#define MAX_AMOUNT 10240
    int memo[MAX_LEN][MAX_AMOUNT];
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());
        //std::fill(memo[0], memo[0] + MAX_LEN * MAX_AMOUNT, INT_MAX);
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 0; j <= amount; j++) memo[i][j] = INT_MAX;
        }
        if (coins.size()) {
            for (int i = 0; i < coins[0] && i < MAX_AMOUNT; i++) memo[0][i] = -1;
        }
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] <= MAX_AMOUNT) memo[i][coins[i]] = 1;
            memo[i][0] = 0;
        }
        return memo[coins.size() - 1][amount] = changes(coins, amount, coins.size() - 1);
    }

    int changes(vector<int> &coins, int amount, int k) {
        if (k < 0) return -1;

        if (memo[k][amount] != INT_MAX) return memo[k][amount];

        if (amount < coins[k]) return memo[k][amount] = changes(coins, amount, k - 1);

        int a = changes(coins, amount - coins[k], k);
        if (a != -1) a += 1;
        int b = changes(coins, amount, k - 1);
        if ((a == -1) && (b == -1)) {
            return memo[k][amount] = -1;
        } else {
            int c;
            if (a == -1) {
                c = b;
            } else if (b == -1) {
                c = a;
            } else {
                c = std::min(a, b);
            }
            return memo[k][amount] = c;
        }
    }
#ifdef TEST
    void test() {
        vector<int> v;
        int amount;

        v = createVector("[1]");
        amount = 0;
        CHECK(coinChange(v, amount), 0);

        v = createVector("[411,412,413,414,415,416,417,418,419,420,421,422]");
        amount = 9864;
        CHECK(coinChange(v, amount), 24);

        v = createVector("[2]");
        amount = 3;
        CHECK(coinChange(v, amount), -1);

        v = createVector("[1, 2, 5]");
        amount = 11;
        CHECK(coinChange(v, amount), 3);

        v = createVector("[2]");
        amount = 3;
        CHECK(coinChange(v, amount), -1);

    }
#endif
};

/*
class Solution {
    vector<int>count;
    int dp(vector<int>& coins, int rem) {
        if (rem < 0) return -1;
        if (rem == 0) return 0;
        if (count[rem] != 0) return count[rem];
        int Min = INT_MAX;
        for (int coin:coins) {
            int res = dp(coins, rem - coin);
            if (res >= 0 && res + 1 < Min) {
                Min = res + 1;
            }
        }
        count[rem] = Min == INT_MAX ? -1 : Min;
        return count[rem];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        count.resize(amount + 1);
        return dp(coins, amount);
    }
};
 */
