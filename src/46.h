class Solution {
    map<size_t, bool> table;
    vector<vector<int>> ret;
    vector<int> v;
    void allPermutation(vector<int> &nums) {
        for (auto x : nums) {
            if (!table[x]) {
                table[x] = true;
                v.push_back(x);
                if (v.size() == nums.size()) ret.push_back(v);
                allPermutation(nums);
                v.pop_back();
                table[x] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        allPermutation(nums);
        return ret;
    }
};
