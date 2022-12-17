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
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        vector<int> v;
        while (!q.empty()) {
            vector<TreeNode*> tmp;
            while (!q.empty()) {
                tmp.push_back(q.front());
                q.pop();
            }
            v.push_back(tmp[tmp.size() - 1]->val);
            for (auto p : tmp) {
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
        }
        return v;
    }
};
