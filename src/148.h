#include "utils.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode *p = head;
        while (p) {
            v.push_back(p->val);
            p = p->next;
        }
        std::sort(v.begin(), v.end());
        p = head;
        for (auto x : v) {
            p->val = x;
            p = p->next;
        }
        return head;
    }
};
