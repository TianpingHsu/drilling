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
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode odd, even;
        ListNode *p = &odd, *q = &even;
        bool flag = true;
        while (head) {
            ListNode* tmp = head->next;
            if (flag) {
                p->next = head;
                p = p->next;
                p->next = NULL;
            } else {
                q->next = head;
                q = q->next;
                q->next = NULL;
            }
            flag = !flag;
            head = tmp;
        }
        p->next = even.next;
        return odd.next;
    }
};
