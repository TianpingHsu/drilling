#include "utils.h"

class Solution {
    void merge(vector<int> &nums, int l, int m, int r) {
        // [l, m), [m, r)
        if (l == m || m == r) return;
        vector<int> a, b;
        for (int i = l; i < m; i++) {
            a.push_back(nums[i]);
        }
        for (int i = m; i < r; i++) {
            b.push_back(nums[i]);
        }
        int p = 0, q = 0;
        while (p < a.size() && q < b.size()) {
            if (a[p] < b[q]) {
                nums[l++] = a[p];
                p++;
            } else {
                nums[l++] = b[q];
                q++;
            }
        }
        while (p != a.size()) {
            nums[l++] = a[p++];
        }
        while (q != b.size()) {
            nums[l++] = b[q++];
        }
        return;
    }
    // nums[l, r)
    void mergeSort(vector<int> &nums, int l, int r) {
        if (l + 1 < r) {
            int m = l + (r - l) / 2;
            mergeSort(nums, l, m);
            mergeSort(nums, m, r);
            merge(nums, l, m, r);
        }
    }
    
    // nums[l, r], assert l < r
    int partition(vector<int> &nums, int l, int r) {
        int pivot = nums[l];    
        int i = l, j = r;
        while (i < j) {
            while (i < j && nums[j] > pivot) j--;
            while (i < j && nums[i] <= pivot) i++;
            std::swap(nums[i], nums[j]);
        }
        std::swap(nums[i], nums[l]);
        return i;
    }

    // nums[l, r]
    void quickSort(vector<int> &nums, int l, int r) {
        if (l >= r) return ;
        int m = partition(nums, l, r);  // l < r
        quickSort(nums, l, m - 1);
        quickSort(nums, m + 1, r);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        //mergeSort(nums, 0, nums.size());
        if (nums.size() <= 1) return nums;
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void test() {
        vector<int> v = createVector("[5,2,3,1]");
        PRINT_VEC(sortArray(v));
    }
};

// heap sort
/*
class Solution {
    int *heap = NULL, size = 0;
    void sink(int k) {
        if (k > size || k <= 0 || 2 * k > size) return ;
        int l = 2 * k, r = 2 * k + 1, candidate = l;
        if (r <= size) {
            candidate = heap[l] > heap[r] ? l : r;
        }
        if (heap[k] < heap[candidate]) {
            std::swap(heap[k], heap[candidate]);
            sink(candidate);
        }
    }
    void heapify() {
        for (int i = size / 2; i >= 1; i--) sink(i);
    }
    bool empty() {return size == 0;}
    int top() {
        return heap[1];
    }
    void heapSort() {
        int n = size;
        while (!empty()) {
            std::swap(heap[1], heap[size]);
            size--;
            sink(1);
        }
        size = n;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        heap = new int[nums.size() + 1];
        size = nums.size();
        for (size_t i = 0; i < nums.size(); i++) {
            heap[i + 1] = nums[i];
        }
        heapSort();
        for (size_t i = 1; i <= size; i++) {
            nums[i - 1] = heap[i];
        }
        delete [] heap;
        return nums;
    }
    void test() {
        vector<int> v = createVector("[5,2,3,1]");
        PRINT_VEC(sortArray(v));
    }
};
*/
