#ifndef __SOLU_H__
#define __SOLU_H__
#include "utils.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy;
        while (head) {
            ListNode *p = head->next;
            ListNode *q = dummy.next;
            dummy.next = head;
            head->next = q;
            head = p;
        }
        return dummy.next;
    }
};

#endif
