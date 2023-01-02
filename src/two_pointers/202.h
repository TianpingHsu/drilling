
#include "utils.h"
class Solution {
public:
    int split_and_sun_of_square(int n) {
        vector<int> v;
        while (n) {
            v.push_back(n % 10);
            n /= 10;
        }
        int sum = 0;
        for (auto x : v) {
            sum += x * x;
        }
        return sum;
    }
    bool isHappy(int n) {
        std::set<int> s;
        while (n != 1) {
            s.insert(n);
            n = split_and_sun_of_square(n);
            if (s.find(n) != s.end()) return false;
        }
        return true;
    }
#ifdef TEST
    void test() {
        int n;
        n = 19;
        CHECK(isHappy(n), true);
        n = 2;
        CHECK(isHappy(n), false);
    }
#endif
};
