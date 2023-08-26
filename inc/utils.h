#ifndef __UTILS_H__
#define __UTILS_H__
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
//#include <format>
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

#define newline() do { printf("\n"); } while(0)

#define MSG(msg) do {cout << msg << endl;} while (0)

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define SHOW(fmt, ...) do { \
    char buf[1024] = {0}; \
    int n = snprintf(buf, sizeof(buf), "%s:%d %s ", __FILENAME__, __LINE__, __FUNCTION__); \
    n = snprintf(buf + n, sizeof(buf) - n, fmt, ##__VA_ARGS__); \
    if (n > sizeof(buf)) { \
        printf("buffer overflow"); \
        exit(-1); \
    } \
    printf(fmt, ##__VA_ARGS__); \
} while (0)

#define CHECK(a, b) do { \
    auto x = (a); \
    decltype(x) y = (b); \
    if (x != y) { \
        printf(RED "FAILED! "); \
        std::cout << "{" << x << "," << y << "}"; \
        printf(" %s != %s in %s() %s:%d\n" RESET, #a, #b, __func__, __FILE__, __LINE__); \
    } else { \
        printf(GREEN "pass.\n" RESET); \
    }\
} while(0)

#define PRINT_VEC(v) do { \
    for (auto x : v) { \
        cout << x << " "; \
    } \
    cout << endl; \
} while(0)

#define PRINT_SEQ(v) do { \
    for (auto x : v) { \
        cout << x << " "; \
    } \
    cout << endl; \
} while(0)

#define PRINT_LIST(l) do {\
    auto p = l; \
    while (p) { \
        printf("%d", p->val); \
        if (p->next) { \
            printf(" -> "); \
        } else { \
            newline(); \
        } \
        p = p->next; \
    } \
} while(0)

#define PRINT_MATRIX(matrix) do { \
    for (auto row : matrix) { \
        PRINT_VEC(row); \
    } \
} while(0)

#define PRINT_MAP(m) do { \
    for (auto &[a, b] : m) { \
        cout << a << " ," << b << endl; \
    } \
}while(0)

#define OUT(x) do { \
    cout << x << endl; \
} while(0)

#define TRACE(fmt, ...) printf("%s:%d %s " fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define STRINGIFY(x) #x

#define EXPRESSION(x) #x " => " STRINGIFY(x)

// https://renenyffenegger.ch/notes/development/languages/C-C-plus-plus/preprocessor/macros/__VA_ARGS__/count-arguments
// https://stackoverflow.com/questions/2124339/c-preprocessor-va-args-number-of-arguments
#define PP_NARG(...) \
         PP_NARG_(__VA_ARGS__,PP_RSEQ_N())
#define PP_NARG_(...) \
         PP_ARG_N(__VA_ARGS__)
#define PP_ARG_N( \
          _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
         _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
         _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
         _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
         _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
         _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
         _61,_62,_63,N,...) N
#define PP_RSEQ_N() \
         63,62,61,60,                   \
         59,58,57,56,55,54,53,52,51,50, \
         49,48,47,46,45,44,43,42,41,40, \
         39,38,37,36,35,34,33,32,31,30, \
         29,28,27,26,25,24,23,22,21,20, \
         19,18,17,16,15,14,13,12,11,10, \
         9,8,7,6,5,4,3,2,1,0

/*
 * code comes from here:
 * https://ideone.com/IfOL44
 */
template<typename T, typename... Args>
T vmin( T arg1, Args&&... args )
{
    T *p[] = { &arg1, &args... };

    return **std::min_element( begin(p), end(p),
            [](T *a, T *b) { return *a < *b; } );
}

template<typename T>
void show(T seq) {
    for (auto x : seq) {
        cout << x << " ";
    }
    cout << endl;
}

TreeNode* createTree(std::string s);
ListNode* createList(std::string s);
std::vector<std::string> split(const std::string &s, char delim);
std::vector<int> createVector(std::string s);

#endif
