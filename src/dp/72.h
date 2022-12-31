
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
        int minDist(const string& word1, const string& word2, int i, int j) {  // top down
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

/*
// bottom up
class Solution {
    public:
#define MAX_LEN 512
        int memo[MAX_LEN][MAX_LEN];
        int minDistance(string word1, string word2) {
            memset(memo[0], -1, sizeof(int) * MAX_LEN * MAX_LEN);
            int max_len = std::max(word1.size(), word2.size());
            for (int i = 0; i <= max_len; i++) {
                memo[0][i] = memo[i][0] = i;
            }
            for (int i = 1; i <= word1.size(); i++) {
                for (int j = 1; j <= word2.size(); j++) {
                    if (word1[i - 1] == word2[j - 1]) {
                        memo[i][j] = memo[i - 1][j - 1];
                    } else {
                        int a = memo[i - 1][j - 1];
                        int b = memo[i - 1][j];
                        int c = memo[i][j - 1];
                        int t = a < b ? a : b;
                        t = t < c ? t : c;
                        memo[i][j] = t + 1;
                    }
                }
            }
            return memo[word1.size()][word2.size()];
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

 */
