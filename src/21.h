#include "utils.h"

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode dummy;
            ListNode *p = &dummy;
            while (list1 && list2) {
                if (list1->val < list2->val) {
                    p->next = list1;
                    list1 = list1->next;
                } else {
                    p->next = list2;
                    list2 = list2->next;
                }
                p = p->next;
            }
            if (list1) p->next = list1;
            if (list2) p->next = list2;
            return dummy.next;
        }
        void test() {

        }
};

/*

dp(n)表示以n结尾的最大子数组和
dp(n) = max{dp(n - 1) + num[i], nums[i]}
注意dp(n)的定义，这意味着最后的结果我们还需要遍历整个dp数组找到最大值返回

class Solution {
    int n = 0;
    int *memo;
    int MAXN = ((unsigned)(-1) << 1) >> 1;
    vector<int> *p;
public:
    int dp(int i) {
        if (i >= n) return 0;
        if (memo[i] != MAXN) return memo[i];
        return memo[i] = std::max(dp(i - 1) + (*p)[i], (*p)[i]);
    }
    int maxSubArray(vector<int>& nums) {
        n = nums.size();
        memo = new int[n];
        for (int i = 0; i < n; i++) memo[i] = MAXN;
        memo[0] = nums[0];
        p = &nums;
        dp(n - 1);
        int x = memo[0];
        for (int i = 0; i < n; i++) {
            if (x < memo[i]) x = memo[i];
        }
        return x;
    }
};
*/

