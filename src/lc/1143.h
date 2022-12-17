#include "utils.h"

class Solution {
    const static int MAX_SIZE = 1024;
    int memo[MAX_SIZE][MAX_SIZE];
    int dfs(const string &text1, const string& text2, int i, int j) {
        if (memo[i][j] != -1) return memo[i][j];
        if (text1[i - 1] == text2[j - 1]) {
            return memo[i][j] = 1 + dfs(text1, text2, i - 1, j - 1);
        } else {
            return memo[i][j] = std::max(dfs(text1, text2, i-1, j), dfs(text1, text2, i, j - 1));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(memo[0], -1, sizeof(int) * MAX_SIZE * MAX_SIZE);
        for (size_t i = 0; i <= std::max(text1.size(), text2.size()); i++) 
            memo[i][0] = memo[0][i] = 0;
        return dfs(text1, text2, text1.size(), text2.size());
    }
};

/*
 
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define N 1001
int memo[N][N];

void init()
{
    memset(memo, -1, sizeof(int) * N * N);
}

int lcs(char* s1, char* s2, int i, int j)
{
    if (i < 0 || j < 0) return 0;

    if (memo[i][j] != -1) return memo[i][j];

    if (s1[i] == s2[j]) {
        return memo[i][j] = lcs(s1, s2, i - 1, j - 1) + 1;
    } else {
        int a = lcs(s1, s2, i - 1, j);
        int b = lcs(s1, s2, i, j - 1);
        return memo[i][j] = MAX(a, b);
    }
}

int longestCommonSubsequence(char * text1, char * text2){
    int l1 = strlen(text1);
    int l2 = strlen(text2);
    init();
    return lcs(text1, text2, l1 - 1, l2 - 1);
}
 */
