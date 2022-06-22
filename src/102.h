class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        vector<vector<int>> ret;
        while (!q.empty()) {
            vector<TreeNode*> v;
            while (!q.empty()) {
                v.push_back(q.front());
                q.pop();
            }
            vector<int> tmp;
            for (auto node : v) {
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                tmp.push_back(node->val);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
