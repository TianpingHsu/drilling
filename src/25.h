#include "utils.h"
class Solution {
    ListNode* reverseIt(ListNode *h, ListNode *t) {
        ListNode dummy(0, NULL);
        ListNode *p = h;
        while (p != t) {
            ListNode *q = p->next;
            p->next = dummy.next;
            dummy.next = p;
            p = q;
        }
        return dummy.next;
    }
    public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = k;
        ListNode *p = head;
        for (int i = 0; i < k; i++) {
            if (p) p = p->next;
            else if (i != k ) return head;
        }
        ListNode *newHead = reverseIt(head, p);
        head->next = reverseKGroup(p, size);
        return newHead;
    }
};
/*
   this is non-recursion version
class Solution {
    ListNode *reverseList(ListNode *head, ListNode *tail) {
        ListNode dummy;
        ListNode *q = head;
        while (head != tail) {
            ListNode *p = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = p;
        }
        if (q) q->next = tail;
        return dummy.next;
    }
    ListNode* getKth(ListNode *head, int k) {
        ListNode *p = head;
        while (--k && p && p->next) p = p->next;
        if (k) return NULL;
        return p;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode *p = &dummy;
        while (1) {
            ListNode *q = getKth(head, k);
            if (!q) return dummy.next;
            ListNode *tail = q->next;
            p->next = reverseList(head, tail);
            p = head;
            head = tail;
        }
        return dummy.next;
    }
};
*/
