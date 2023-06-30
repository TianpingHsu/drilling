
#include "inc/utils.h"
class Solution {
public:
#ifdef TEST
    void test() {
        for (auto v = {1, 2, 3}; auto x : v) {
            OUT(x);
        }
    }
#endif
};

