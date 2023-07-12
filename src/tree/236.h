
#include "inc/utils.h"

class Solution {
public:
    bool ancestor(TreeNode* p, TreeNode* q) {
        if (!p) return false;
        if (p == q) return true;
        return ancestor(p->left, q) || ancestor(p->right, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root;
        bool a = ancestor(root->left, p);
        if (a) {  // p is child of root->left
            bool b = ancestor(root->left, q);
            if (b) {  // both p and q are child of root->left
                return lowestCommonAncestor(root->left, p, q);
            } else {  // p is child of root->left, and q is not a child of root->left
                return root;
            }
        } else {  // p is child of root->right
            bool b = ancestor(root->right, q);
            if (b) {  // both p and q are child of root->right
                return lowestCommonAncestor(root->right, p, q);
            } else {  // p is child of root->right, and q is not a child of root->right
                return root;
            }
        }
    }


#ifdef TEST
    TreeNode* search(TreeNode* root, int value) {
        if (root == NULL) return NULL;
        if (root->val == value) return root;
        TreeNode* p = search(root->left, value);
        if (p) return p;
        return search(root->right, value);
    }
    void test() {
        TreeNode* root = createTree("[3,5,1,6,2,0,8,null,null,7,4]");
        TreeNode* p = search(root, 5);
        TreeNode* q = search(root, 1);
        TreeNode* ret = lowestCommonAncestor(root, p, q);
        CHECK(ret->val, 3);
    }
#endif
};
