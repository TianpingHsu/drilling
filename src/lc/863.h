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
    map<TreeNode*, TreeNode*> parent;
    set<TreeNode*> vis;
    vector<int> ret;
    void markParent(TreeNode* root) {
        if (!root) return;
        parent[root->left] = root;
        parent[root->right] = root;
        markParent(root->left);
        markParent(root->right);
    }
    void down(TreeNode* root, int k) {
        if (!root) return;
        if (vis.count(root)) return;
        if (k == 0) ret.push_back(root->val);
        vis.insert(root);
        down(root->left, k - 1);
        down(root->right, k - 1);
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent[root] = NULL;
        markParent(root);
        down(target, k);
        while (--k >= 0 && parent[target]) {
            target = parent[target];
            down(target, k);
        }
        return ret;
    }
};
