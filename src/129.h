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
    int sum = 0;
    void visit(TreeNode* root, int current, int depth) {
        if (!root) {
            return;
        }
        current *= 10;
        current += root->val;
        if (!root->left && !root->right) {
            sum += current;
            return;
        }
        visit(root->left, current, depth + 1);
        visit(root->right, current, depth + 1);
    }
public:
    int sumNumbers(TreeNode* root) {
        visit(root, 0, 0);
        return sum;
    }
};
