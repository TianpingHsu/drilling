#ifndef __SOLU_H__
#define __SOLU_H__
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "./inc/utils.h"
#include "./inc/ListNode.h"
using namespace std;

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

#endif
