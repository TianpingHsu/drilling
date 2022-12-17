class Solution {
    int visit(TreeNode* root) {
        if (!root) return 0;
        int l = visit(root->left);
        int r = visit(root->right);
        return 1 + max(l, r);
    }
public:
    int maxDepth(TreeNode* root) {
        return visit(root);
    }
};
