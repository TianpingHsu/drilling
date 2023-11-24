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
    void test() {

    }
};

/*
 *
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0);
        ListNode *q = head;
        while (q) {
            ListNode *p = q;
            q = q->next;
            p->next = dummy.next;
            dummy.next = p;
        }
        return dummy.next;
    }

    ListNode* reverseListRecur(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        ListNode *p = reverseListRecur(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }


#ifdef TEST
    void test() {
        ListNode *head = createList("[1,2,3,4,5]");
        printList(head);
        printList(reverseListRecur(head));
    }
#endif
};
*/
