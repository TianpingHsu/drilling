/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int len(ListNode *l) {
        if (!l) return 0;
        return 1 + len(l->next);
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = len(head);
        int k = length - n;
        ListNode dummy(0, head);
        ListNode *p = &dummy;
        while (k) {
            p = p->next;
            k --;
        }
        if (p->next) p->next = p->next->next;
        return dummy.next;
    }
};
