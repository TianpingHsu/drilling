
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
        ListNode dummy(0, head);
        ListNode *slow = &dummy, *fast = head;
        while (fast) {
            ListNode *p = fast->next;
            while (p && (p->val == fast->val)) p = p->next;
            slow = slow->next;
            slow->val = fast->val;
            fast = p;
        }
        slow->next = NULL;
        return dummy.next;
    }
#ifdef TEST
    void test() {
        ListNode *head = NULL;
        head = createList("[1,1,2]");
        PRINT_LIST(deleteDuplicates(head));

        head = createList("[1,1,2,3,3]");
        PRINT_LIST(deleteDuplicates(head));
    }
#endif
};
