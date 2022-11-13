#include "utils.h"

class Node {
public:
    int val;
    Node* left = NULL;
    Node* right = NULL;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
    Node* pre = NULL;
    void dfs(Node* root) {
        if (!root) return;
        dfs(root->left);
        if (!pre) pre = root;
        else {
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        dfs(root->right);
    }
    Node* minimal(Node* root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        Node *head = minimal(root);
        dfs(root);        
        head->left = pre;
        pre->right = head;
        return head;
    }
};

