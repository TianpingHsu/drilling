/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy;
        ListNode *p = &dummy;
        while (l1 && l2) {
            int x = l1->val + l2->val + carry;
            carry = x / 10;
            x %= 10;
            p->next = new ListNode(x);
            l1 = l1->next;
            l2 = l2->next;
            p = p->next;
        }
        while (l1) {
            int x = l1->val + carry;
            carry = x / 10;
            x %= 10;
            p->next = new ListNode(x);
            l1 = l1->next;
            p = p->next;
        }
        while (l2) {
            int x = l2->val + carry;
            carry = x / 10;
            x %= 10;
            p->next = new ListNode(x);
            l2 = l2->next;
            p = p->next;
        }
        if (carry) {
            p->next = new ListNode(carry);
        }
        return dummy.next;
    }
};
