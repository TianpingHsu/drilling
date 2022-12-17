#include "utils.h"

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            set<ListNode*> s;
            while (head) {
                if (s.find(head) != s.end()) return true;
                else s.insert(head);
                head = head->next;
            }
            return false;
        }

        void test() {
            //CHECK_INT(lengthOfLongestSubstring("au"), 2);
        }
};

