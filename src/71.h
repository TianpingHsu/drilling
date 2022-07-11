#include "utils.h"

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string item;
        vector<string> v;
        while (std::getline(ss, item, '/')) {
            if (!item.empty()) v.push_back(item);
        }
        if (v.empty()) return "/";
        PRINT_VEC(v);
        // skip preceding ".."
        size_t i = 0;
        while (v[i] == "..") i++;
        vector<string> tmp;
        for (; i < v.size(); i++) {
            if (v[i] == ".") continue;
            if (v[i] == "..") {
                if (!tmp.empty()) tmp.pop_back();
                continue;
            }
            tmp.push_back(v[i]);
        }
        PRINT_VEC(tmp);
        item.clear();
        for (auto x : tmp) {
            item += "/" + x;
        }
        return item.empty() ? "/" : item;
    }
    void test() {
        //OUT(simplifyPath("/a/../../b/../c//.//"));
        OUT(simplifyPath("/a//b////c/d//././/.."));
    }
};
