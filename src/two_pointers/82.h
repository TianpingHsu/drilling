
#include "utils.h"

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode dummy(head->val - 1, head);
        ListNode *p = &dummy, *q = dummy.next;
        while (true) {
            ListNode *r = q->next;
            while (r && r->val == q->val) r = r->next;
            if (r == q->next) {
                p->next = q;
                p = p->next;
            }
            q = r;
            if (!q){
                p->next = q;
                break;
            } 
        }
        return dummy.next;
    }

#ifdef TEST
    void test() {
        ListNode *head = createList("[1,2,3,3,4,4,5]");
        printList(deleteDuplicates(head));
        head = createList("[1,1,1,2,3]");
        printList(deleteDuplicates(head));
        head = createList("[1,1]");
        printList(deleteDuplicates(head));
    }
#endif
};
