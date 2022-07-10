class Solution {
    void moveForward(vector<int> &nums, int j, int k) {
        if (k == 0) return;
        while (j < nums.size()) {
            int tmp = nums[j];
            nums[j - k] = tmp;
            j++;
        }
    }
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int i = 0, j = i + 1, n = nums.size();
        while (j < n) {
            while (j < n && nums[i] == nums[j]) j++;
            int gap = j - i - 1;
            moveForward(nums, j, gap);
            n -= gap;
            ++i;
            j = i + 1;
        }
        return n;
    }
};
