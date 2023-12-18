#include "utils.h"

// https://www.zhihu.com/question/36132386

namespace PoC {
    // arr[l, r)
    template<typename T>
        int lower_bound(T* arr, int l, int r, T target) {
            while (l < r) {
                int m = l + ((r - l) >> 1);
                if (arr[m] >= target) r = m;
                else l = m + 1;
            }
            return l;
        }

    // arr[l, r)
    template<typename Seq>
        int lower_bound(Seq arr, int l, int r, typename Seq::value_type target) {
            while (l < r) {
                int m = l + ((r - l) >> 1);
                if (arr[m] >= target) r = m;
                else l = m + 1;
            }
            return l;
        }

    // arr[l, r)
    template<typename T>
        int upper_bound(T* arr, int l, int r, T target) {
            while (l < r) {
                int m = l + ((r - l) >> 1);
                if (arr[m] > target) r = m;
                else l = m + 1;
            }
            return l;
        }

    // arr[l, r)
    template<typename Seq>
        int upper_bound(Seq arr, int l, int r, typename Seq::value_type target) {
            while (l < r) {
                int m = l + ((r - l) >> 1);
                if (arr[m] > target) r = m;
                else l = m + 1;
            }
            return l;
        }

}

TEST_CASE("search with lower_bound", "[.][lower_bound]") {
    vector<int> v;
    {
        v = {0, 1, 2, 3,3,3, 4, 5, 6};
        int a = PoC::lower_bound(v, 0, v.size(), 3);
        auto b = std::lower_bound(v.begin(), v.end(), 3);
        int c = b - v.begin();
        REQUIRE(a == c);
    }
    {
        int a[] = {0, 1, 2, 3,3,3, 4, 5, 6};
        int x = PoC::lower_bound(a, 0, sizeof(a) / sizeof(int), 3);
        auto b = std::lower_bound(a, a + sizeof(a) / sizeof(int), 3);
        int y = b - a;
        REQUIRE(x == y);
    }
}

TEST_CASE("search with upper_bound", "[.][upper_bound]") {
    vector<int> v;
    {
        v = {0, 1, 2, 3,3,3, 4, 5, 6};
        int a = PoC::upper_bound(v, 0, v.size(), 3);
        auto b = std::upper_bound(v.begin(), v.end(), 3);
        int c = b - v.begin();
        REQUIRE(a == c);
    }
    {
        int a[] = {0, 1, 2, 3,3,3, 4, 5, 6};
        int x = PoC::upper_bound(a, 0, sizeof(a) / sizeof(int), 3);
        auto b = std::upper_bound(a, a + sizeof(a) / sizeof(int), 3);
        int y = b - a;
        REQUIRE(x == y);
    }
}

