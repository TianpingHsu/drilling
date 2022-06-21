/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> sa;
        while (headA) {
            sa.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (sa.find(headB) != sa.end()) return headB;
            headB = headB->next;
        }
        return NULL;
    }
};
