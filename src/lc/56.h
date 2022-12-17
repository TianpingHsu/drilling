#include "utils.h"

class Solution {
    bool tryMerge(const vector<int> &a, const vector<int> &b) {
        return a[1] >= b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        if (intervals.empty()) return ret;
        sort(intervals.begin(), intervals.end());
        stack<vector<int>> q;
        q.push(intervals[0]);
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> current = intervals[i];
            vector<int> top = q.top();
            q.pop();
            if (tryMerge(top, current)) {
                q.push({min(top[0], current[0]), max(top[1], current[1])});
            } else {
                q.push(top);
                q.push(current);
            }
        }
        while (!q.empty()){
            ret.push_back(q.top());
            q.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    void test() {
        {
            vector<vector<int>> v;
            v.push_back({1,3});
            v.push_back({2,6});
            v.push_back({8,10});
            v.push_back({15,18});
            v = merge(v);
            for (auto x : v) PRINT_VEC(x);
        }
        /*
        vector<vector<int>> v;
        v.push_back({2,3});
        v.push_back({4,5});
        v.push_back({6,7});
        v.push_back({1,10});
        v = merge(v);
        for (auto x : v) PRINT_VEC(x);
        */
    }
};

