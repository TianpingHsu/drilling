class Solution {
public:
    int majorityElement(vector<int>& nums) {
        queue<int> q;
        q.push(nums[0]);
        int c = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            if (q.front() != nums[i]) {
                if (--c == 0) {
                    q.pop();
                    q.push(nums[i]);
                    c = 1;
                }
            } else {
                c++;
            }
        }
        return q.front();
    }
};
