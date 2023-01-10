#include "solu.h"
#include "utils.h"

TreeNode* createTree(string s) {
    for (auto it = s.begin(); it != s.end();) {
        if (*it == ' ' || *it == '[' || *it == ']') {
            it = s.erase(it);
            continue;
        }
        it++;
    }
    if (s.empty()) return NULL;
    vector<string> vs = split(s, ',');
    vector<TreeNode*> tree;
    for (auto x : vs) {
        if (x == "null") {
            tree.push_back(NULL);
        } else {
            TreeNode *node = new TreeNode(stoi(x));
            tree.push_back(node);
        }
    }
    for (size_t i = 0; i < tree.size(); i++) {
        if (!tree[i]) continue;
        size_t l = 2 * i + 1, r = 2 * i + 2;
        if (l < tree.size()) tree[i]->left = tree[l];
        if (r < tree.size()) tree[i]->right = tree[r];
    }
    return tree[0];
}

ListNode* createList(string s) {
    for (auto it = s.begin(); it != s.end(); ) {
        if (*it == ' ' || *it == '[' || *it == ']') {
            it = s.erase(it);
            continue;
        }
        it++;
    }
    if (s.empty()) return NULL;
    vector<string> vs = split(s, ',');
    ListNode dummy;
    ListNode *p = &dummy;
    for (auto x : vs) {
        int val = stoi(x);
        p->next = new ListNode(val, NULL);
        p = p->next;
    }
    return dummy.next;
}

vector<int> createVector(string s) {
    vector<int> v;
    for (auto it = s.begin(); it != s.end();) {
        if (*it == ' ' || *it == '[' || *it == ']') {
            it = s.erase(it);
            continue;
        }
        it++;
    }
    if (s.empty()) return v;
    vector<string> vs = split(s, ',');
    for (auto x : vs) {
        v.push_back(stoi(x));
    }
    return v;
}

std::vector<std::string> split(const std::string &s, char delim = ',') {
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

int main() {
    Solution s;
    s.test();
    return 0;
}
