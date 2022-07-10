class Solution {
    vector<int> tmp;
    vector<vector<int>> ret;
    void dfs(const vector<int> & ns, int idx, int target) {
        if (idx >= ns.size() || target < 0) {
            return;
        }
        tmp.push_back(ns[idx]);
        if (target - ns[idx] == 0) {
            ret.push_back(tmp);
            tmp.pop_back();
            return;
        }
        dfs(ns, idx, target - ns[idx]);
        tmp.pop_back();
        dfs(ns, idx + 1, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return ret;
    }
};
