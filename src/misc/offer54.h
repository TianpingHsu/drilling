/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    priority_queue<int> q;
    void dfs(TreeNode *root) {
        if (!root) return;
        q.push(root->val);
        dfs(root->left);
        dfs(root->right);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        dfs(root);
        int ret = 0;
        while (k--) {
            ret = q.top();
            q.pop();
        }
        return ret;
    }
};
