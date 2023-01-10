
#include "../../../inc/utils.h"

bool is_prime(const int n) {  // n >= 2
    int up_bound = sqrt(n);
    for (int i = 2; i <= up_bound; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

#ifdef TEST
int main() {
    for (int i = 2; i <= 100; i++) {
        if (is_prime(i)) {
            printf("%d is prime\n", i);
        }
    }
    return 0;
}
#endif
