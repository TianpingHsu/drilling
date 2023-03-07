
#include "../../../inc/utils.h"

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

// a[l...r]
void quick_sort(int *a, int l, int r) {
    if (l >= r) return;
    int m = partition(a, l, r);
    quick_sort(a, l, m - 1);
    quick_sort(a, m + 1, r);
}

#ifdef TEST
int main() {
    int a[] = {8, 1, 2, 9, 7, 5, 6, 0, 4, 3};
    quick_sort(a, 0, sizeof(a)/sizeof(int) - 1);
    for (auto x : a) printf("%d ", x);
    newline();
}
#endif

