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
    int getLen(ListNode *head, ListNode **tail) {
        *tail = head;
        if (!head) return 0;
        int sum = 0;
        while ((*tail)->next) {
            sum++;
            (*tail) = (*tail)->next;
        }
        return sum + 1;
    }
    ListNode *reverseList(ListNode *head) {
        ListNode dummy;
        dummy.next = head;
        if (head) {
            ListNode *p = head->next, *q = p;
            while (q) {
                q = p->next;
                p->next = dummy.next;
                dummy.next = p;
                p = q;
            }
            head->next = NULL;
        }
        return dummy.next;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * tail = NULL;
        int len = getLen(head, &tail);
        if (!len) return NULL;
        k = len - k % len;
        if (!k) return head;
        ListNode *p = head;
        while (--k) {
            p = p->next;
        }
        ListNode *q = p->next;
        p->next = NULL;
        ListNode *ra = reverseList(head);
        ListNode *rb = reverseList(q);
        head->next = rb;
        return reverseList(ra);
    }
};
