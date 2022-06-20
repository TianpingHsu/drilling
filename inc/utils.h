#ifndef __UTILS_H__
#define __UTILS_H__

#define CHECK_INT(a, b) do { \
    long long int x = (a); \
    long long int y = (b); \
    if (x != y) { \
        printf("FAILED! => output: %lld, expected: %lld\n", x, y); \
    } else { \
        printf("pass.\n"); \
    }\
} while(0)

#define CHECK_BOOL(a, b) do {\
    bool x = (a); \
    if (x != b) { \
        printf("FAILED! => output: %s, expected: %s\n", x ? "true" : "false", y ? "true" : "false"); \
    } else { \
        printf("pass.\n"); \
    } \
} while(0)

#endif
