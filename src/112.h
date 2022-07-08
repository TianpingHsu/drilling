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
    int target;
    bool flag = false;
    void dfs(TreeNode* root, int sum) {
        if (!root) return ;
        if (!root->left && !root->right) {
            if (sum + root->val == target) flag = true;
            return;
        }
        dfs(root->left, sum + root->val);
        dfs(root->right, sum + root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        dfs(root, 0);
        return flag;
    }
};
