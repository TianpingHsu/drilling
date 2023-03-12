#include <cstdio>

int count_1s(unsigned char c) {
    unsigned char mask = 0x01;
    int count = 0;
    do {
        printf("%d\n", mask);
        if (mask & c) count++; 
    } while (mask <<= 1);
    return count;
}

int main() {
    printf("%d\n", count_1s(12));
}
