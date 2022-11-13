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
    vector<int> tmp;
    void preorder(TreeNode* root) {
        if (!root) {
            tmp.push_back(-111);
            return;
        }
        tmp.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(TreeNode* root) {
        if (!root) {
            tmp.push_back(-111);
            return;
        }
        inorder(root->left);
        tmp.push_back(root->val);
        inorder(root->right);
    }

    void haha(TreeNode *root) {
        if (!root) return;
        std::swap(root->left, root->right);
        haha(root->left);
        haha(root->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        vector<int> lp, li, rp, ri;
        tmp.clear();
        preorder(root->left);
        lp = tmp;
        tmp.clear();
        inorder(root->left);
        li = tmp;

        haha(root->right);
        tmp.clear();
        preorder(root->right);
        rp = tmp;
        tmp.clear();
        inorder(root->right);
        ri = tmp;
        return lp == rp && li == ri;
    }
};
