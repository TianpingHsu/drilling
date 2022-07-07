#include "utils.h"

class Solution {
    vector<int> v;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
public:
    void test() {
        TreeNode *root = createTree("[5,1,4,null,null,3,6]");
        inorder(root);
        PRINT_VEC(v);

        v.clear();
        ListNode *head = createList("[4,2,1,3]");
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        PRINT_VEC(v);
    }
};
