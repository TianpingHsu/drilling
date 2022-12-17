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
    int d = 0;
    map<TreeNode*, int> table;
    int depth(TreeNode* root) {
        if (!root) return 0;
        int l =depth(root->left);
        int r = depth(root->right);
        table[root->left] = l;
        table[root->right] = r;
        return table[root] = std::max(l, r) + 1;
    }
    int dfs(TreeNode *root) {
        if (!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int tmp = std::max(l, r);
        tmp = std::max(tmp, 1 + depth(root->left) + depth(root->right));
        if (tmp > d) d = tmp;
        return tmp;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        table[NULL] = 0;
        dfs(root);
        return d - 1;
    }
};
