class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        vector<vector<int>> ret;
        bool dire = true;
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
            if (!dire) {
                std::reverse(tmp.begin(), tmp.end());
            }
            ret.push_back(tmp);
            dire = !dire;
        }
        return ret;

    }
};
