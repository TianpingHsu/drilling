class Solution {
    vector<int> tmp;
    vector<vector<int>> ret;
    void dfs(vector<int> &nums, int idx) {
        if (idx == nums.size()) {
            ret.push_back(tmp);
            return ;
        }
        dfs(nums, idx+1);
        tmp.push_back(nums[idx]);
        dfs(nums, idx + 1);
        tmp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }
};
