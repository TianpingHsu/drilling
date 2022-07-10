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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummy(0, head);
        ListNode *p = &dummy, *q = p->next, *r = q->next;
        while (q && r) {
            ListNode *newhead = r->next;
            p->next = r;
            r->next = q;
            q->next = newhead;
            p = q;
            if ((q = p->next) && (r = q->next)) {

            } else {
                break;
            }
        }
        return dummy.next;
    }
};

/*
class Solution {

public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)  return head;
        ListNode* p = head, *q = head->next, *r = q->next;
        q->next = p;
        p->next = swapPairs(r);
        return q;
    }
};
 */
