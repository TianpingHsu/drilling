
#include "utils.h"

int sieve_of_Eratosthenes(const int n) {
    int *is_prime = new int[n + 1];
    memset(is_prime, -1, sizeof(int) * (n + 1));  // -1 stands for true
    is_prime[0] = is_prime[1] = 0;  // 0 and 1 is not prime
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] == -1) {  // is i is prime
            count++;
            for (int factor = 2; ; factor++) {
                int x = factor * i;
                if (x > n) break;
                is_prime[x] = 0;
            }
        }
    }
#ifdef TEST
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) printf("%d ", i);
    }
    newline();
#endif
    return count;
}

#ifdef TEST
int main() {
    OUT(sieve_of_Eratosthenes(100));
    return 0;
}
#endif
