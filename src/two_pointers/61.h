
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
    int len(ListNode* head) {
        int n = 0;
        while (head) {
            n++;
            head = head->next;
        }
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int l = len(head); 
        k = k % l;
        if (!k) return head;
        ListNode dummy(0, head);
        ListNode *fast = &dummy, *slow = &dummy;
        while (k--) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *p = slow->next;
        slow->next = NULL;
        fast->next = head;
        return p;
    }

#ifdef TEST
    void test() {
        //ListNode *head = createList("[1,2,3,4,5]");
        ListNode *head = createList("[1]");
        printList(rotateRight(head, 2));
        //printList(rotateRight(head, 3));
    }
#endif
};
