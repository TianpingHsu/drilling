

## 136. 只出现一次的数字
https://leetcode.cn/problems/single-number/  

```C++
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto x : nums) {
            ret ^= x;
        }
        return ret;
    }
```


## 169. 多数元素
https://leetcode.cn/problems/majority-element/  

```C++
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }

```


## 88. 合并两个有序数组
https://leetcode.cn/problems/merge-sorted-array/  
```C++
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1, i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while (i >= 0) nums1[k--] = nums1[i--];
        while (j >= 0) nums1[k--] = nums2[j--];
    }
```

## 240. 搜索二维矩阵 II
https://leetcode.cn/problems/search-a-2d-matrix-ii/  
```C++
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int x = 0, y = matrix[0].size() - 1;
            int m = matrix.size(), n = matrix[0].size();
            while (x >= 0 && x < m && y >= 0 && y < n) {
                if (target == matrix[x][y]) {
                    return true;
                } else if (target > matrix[x][y]) {
                    x++;
                } else {
                    y--;
                }
            }
            return false;
        }
```
