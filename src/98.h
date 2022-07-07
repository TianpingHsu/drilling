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
    vector<int> v;
    bool help(TreeNode* root) {
        if (!root) return true;
        if (root->left && root->left->val >= root->val) return false;
        if (root->right && root->right->val <= root->val) return false;
        return help(root->left) && help(root->right);
    }
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    bool isOrdered() {
        if (v.empty()) return true;
        for (size_t i = 0; i < v.size() - 1; i++) {
            if (v[i] >= v[i + 1]) return false;
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return help(root) && isOrdered();
    }
};
