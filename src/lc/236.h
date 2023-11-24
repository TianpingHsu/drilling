class Solution {
    vector<TreeNode*> vp, vq;
    TreeNode *m_p, *m_q;
    void dfs(TreeNode* root, vector<TreeNode*> &v) {
        if (!root) return;
        v.push_back(root);
        if (root == m_p) {
            vp = v;
        } else if (root == m_q) {
            vq = v;
        }
        dfs(root->left, v);
        if (root->left) v.pop_back();
        dfs(root->right, v);
        if (root->right) v.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        m_p = p, m_q = q;
        vector<TreeNode*> v;
        dfs(root, v);
        size_t i;
        for (i = 0; i < vp.size() && i < vq.size(); i++) {
            if (vp[i] != vq[i]) break;
        }
        if (i == vp.size()) return vp[i - 1];
        if (i == vq.size()) return vq[i - 1];
        return vp[i - 1];
    }
};

/*
class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        } 
        return lson || rson || (root->val == p->val || root->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetc-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

/*

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
*/
