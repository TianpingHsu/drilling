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
        map<int, int> m;
        m[101] = 1;
        ListNode *p = head;
        while (p) {
            if (m.find(p->val) == m.end()) m[p->val] = 1;
            else m[p->val]++;
            p = p->next;
        }
        ListNode dummy(101, head);
        p = &dummy;
        while (p->next) {
            if (m[p->next->val] != 1) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        return dummy.next;
    }
};
