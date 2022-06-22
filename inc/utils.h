#ifndef __UTILS_H__
#define __UTILS_H__
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "ListNode.h"
#include "TreeNode.h"
using namespace std;

// https://stackoverflow.com/questions/1961209/making-some-text-in-printf-appear-in-green-and-red
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define CHECK_INT(a, b) do { \
    long long int x = (a); \
    long long int y = (b); \
    if (x != y) { \
        printf(RED "FAILED! => output: %lld, expected: %lld\n" RESET, x, y); \
    } else { \
        printf("pass.\n"); \
    }\
} while(0)

#define CHECK_BOOL(a, b) do {\
    bool x = (a); \
    if (x != b) { \
        printf(RED "FAILED! => output: %s, expected: %s\n" RESET, x ? "true" : "false", y ? "true" : "false"); \
    } else { \
        printf("pass.\n"); \
    } \
} while(0)

#define PRINT_VEC(v) do { \
    for (auto x : v) { \
        cout << x << " "; \
    } \
    cout << endl; \
} while(0)

#define newline() do { printf("\n"); } while(0)

#define MSG(msg) do {cout << msg << endl;} while (0)

#endif
