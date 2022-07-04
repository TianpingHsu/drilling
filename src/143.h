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
    ListNode *reverseList(ListNode *p) {
        ListNode dummy;
        while (p) {
            ListNode *t = p->next;
            p->next = dummy.next;
            dummy.next = p;
            p = t;
        }
        return dummy.next;
    }
    ListNode *mergeList(ListNode *l1, ListNode *l2) {
        ListNode dummy;
        ListNode *p = &dummy;
        while (l1 && l2) {
            p->next = l1;
            l1 = l1->next;
            p->next->next = l2;
            l2 = l2->next;
            p = p->next->next;
        }
        if (l1) p->next =l1;
        return dummy.next;
    }
public:
    void reorderList(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *fast = &dummy, *slow = &dummy;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *a = head;
        ListNode *b = slow->next;
        slow->next = NULL;
        b = reverseList(b);
        mergeList(a, b);
    }
};
