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

#define CHECK(a, b) do { \
    auto x = (a); \
    decltype(x) y = (b); \
    if (x != y) { \
        printf(RED "FAILED! "); \
        std::cout << "{" << x << "," << y << "}"; \
        printf(" %s != %s in %s() %s:%d\n" RESET, #a, #b, __func__, __FILE__, __LINE__); \
    } else { \
        printf("pass.\n"); \
    }\
} while(0)

#define PRINT_VEC(v) do { \
    for (auto x : v) { \
        cout << x << " "; \
    } \
    cout << endl; \
} while(0)

#define PRINT_MATRIX(matrix) do { \
    for (auto row : matrix) { \
        PRINT_VEC(row); \
    } \
} while(0)

#define OUT(x) do { \
    cout << x << endl; \
} while(0)

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

TreeNode* createTree(std::string s);
ListNode* createList(std::string s);
std::vector<std::string> split(const std::string &s, char delim);
std::vector<int> createVector(std::string s);
//std::vector<vector<int>> createMatrix(std::string s);

#endif
