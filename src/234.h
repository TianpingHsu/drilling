#include "utils.h"

/*
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        static ListNode *front = head;
        if (head) {
            if (!isPalindrome(head->next)) return false;
            if (head->val != front->val) return false;
            front = front->next;
        }
        return true;
    }
};
*/
class Solution {
    ListNode* frontPointer;
public:
    bool recursivelyCheck(ListNode* currentNode) {
        if (currentNode != nullptr) {
            if (!recursivelyCheck(currentNode->next)) {
                return false;
            }
            if (currentNode->val != frontPointer->val) {
                return false;
            }
            frontPointer = frontPointer->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
};

