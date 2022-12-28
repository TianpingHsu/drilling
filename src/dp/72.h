
#include "utils.h"

class Solution {
    public:
#define MAX_LEN 512
        int memo[MAX_LEN][MAX_LEN];
        int minDistance(string word1, string word2) {
            memset(memo[0], -1, sizeof(int) * MAX_LEN * MAX_LEN);
            for (int i = 0; i <= word2.size(); i++) {
                memo[0][i] = i;
            }
            for (int i = 0; i <= word1.size(); i++) {
                memo[i][0] = i;
            }

            return minDist(word1, word2, word1.size(), word2.size());
        }

        // min dist of word1[0...i-1] and word2[0...j-1]
        int minDist(const string& word1, const string& word2, int i, int j) {
            if (memo[i][j] != -1) return memo[i][j];
            if (word1[i - 1] == word2[j - 1]) {
                return memo[i][j] = minDist(word1, word2, i - 1, j - 1);
            } else {
                int a = minDist(word1, word2, i - 1, j - 1) + 1;
                int b = minDist(word1, word2, i - 1, j) + 1;
                int c = minDist(word1, word2, i, j - 1) + 1;
                int t = a < b ? a : b;
                t = t < c ? t : c;
                return memo[i][j] = t;
            }
        }

#ifdef TEST
        void test() {
            CHECK(minDistance("ab", "a"), 1);
            CHECK(minDistance("intention", "execution"), 5);
            CHECK(minDistance("", ""), 0);
            CHECK(minDistance("", "a"), 1);
        }
#endif

};

