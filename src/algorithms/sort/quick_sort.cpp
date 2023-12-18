
#include "utils.h"

// a[l...r]
int partition(int *a, int l, int r) {
    int m = l;
    int pivot = a[l];
    while (l < r) {
        while (l < r && a[r] > pivot) r--;
        while (l < r && a[l] <= pivot) l++;
        std::swap(a[l], a[r]);
    }
    std::swap(a[m], a[l]);
    return l;
}

/*
// a[l, r)
int partition(int *a, int l, int r) {
    int pivot = l;
    while (l < r)  {
        while (l < r && a[r - 1] > a[pivot]) r--;
        while (l < r && a[l] <= a[pivot]) l++;
        std::swap(a[l], a[r - 1]);
    }
}
*/

// a[l...r]
void quick_sort(int *a, int l, int r) {
    if (l >= r) return;
    int m = partition(a, l, r);
    quick_sort(a, l, m - 1);
    quick_sort(a, m + 1, r);
}

