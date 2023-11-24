
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1, head);
        ListNode *fast = &dummy, *slow = &dummy;
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
#ifdef TEST
    void test() {
        ListNode* head = createList("[1,2,3,4,5]");
        printList(head);
        ListNode* p = removeNthFromEnd(head, 2);
        printList(p);

        head = createList("[1]");
        printList(head);
        p = removeNthFromEnd(head, 1);
        printList(p);

        head = createList("[1,2]");
        printList(head);
        p = removeNthFromEnd(head, 1);
        printList(p);
    }
#endif
};
