class Solution {
    static const int MAX_N = 2 * 10e4 + 10;
    int lm[MAX_N], rm[MAX_N];
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int idx = 0;
        lm[idx] = height[idx];
        for (size_t i = 1; i < height.size(); i++) {
            if (height[i] < height[idx]) lm[i] = height[idx];
            else {
                idx = i;
                lm[i] = height[i];
            }
        }
        idx = height.size() - 1;
        rm[idx] = height[idx];
        for (int i = height.size() - 1; i >= 0; i--) {
            if (height[i] < height[idx]) rm[i] = height[idx];
            else {
                idx = i;
                rm[i] = height[i];
            }
        }
        int s = 0;
        for (size_t i = 0; i < height.size(); i++) {
            int max_h = std::min(lm[i], rm[i]);
            if (max_h > height[i]) s += (max_h - height[i]);
        }
        return s;
    }
};
