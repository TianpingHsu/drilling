#include "utils.h"

class Solution {
    double epsilon = 0.0001;
    bool good_enough(double x, double guess) {
        if (abs(x - guess * guess) < epsilon) return true;
        return false;
    }
    double square_root(double x, double guess) {
        if (good_enough(x, guess)) return guess;
        return square_root(x, (guess + x/guess)/2.0);
    }
public:
    int mySqrt(int x) {
        return square_root(x, 1);
    }
    void test() {
        cout << mySqrt(2147395599) << endl;
    }
};
