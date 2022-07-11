/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool sameTree(TreeNode *a, TreeNode *b) {
        queue<TreeNode*> qa, qb;
        qa.push(a), qb.push(b);
        while (!qa.empty() && !qb.empty()) {
            vector<TreeNode*> va, vb;
            while (!qa.empty()) {
                va.push_back(qa.front());
                qa.pop();
            }
            while (!qb.empty()) {
                vb.push_back(qb.front());
                qb.pop();
            }
            if (va.size() != vb.size()) return false;
            for (size_t i = 0; i < va.size(); i++) {
                if (va[i] && vb[i] && (va[i]->val != vb[i]->val))  return false;
                if (va[i] && !vb[i]) return false;
                if (!va[i] && vb[i]) return false;
                if (va[i]) {
                    qa.push(va[i]->left);
                    qa.push(va[i]->right);
                }
                if (vb[i]) {
                    qb.push(vb[i]->left);
                    qb.push(vb[i]->right);
                }
            }
        }
        return qa.empty() && qb.empty();
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root && subRoot) return false;
        if (root && !subRoot) return false;
        if (root->val == subRoot->val) {
            if (sameTree(root, subRoot)) return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
};
