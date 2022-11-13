#include "utils.h"

class Solution {
    void getTokens(const string &s, vector<string> &tokens) {
        for (size_t i = 0; i < s.size(); i++) {
            while (s[i] == ' ') i++;  // skip
            size_t j = i;
            while (j < s.size() && s[j] != ' ') j++;
            string token;
            for (size_t k = i; k < j ;k++) token.push_back(s[k]);
            if (!token.empty())tokens.push_back(token);
            i = j;
        }
    }
public:
    string reverseWords(string s) {
        std::reverse(s.begin(), s.end());
        vector<string> tokens;
        getTokens(s, tokens);
        s.clear();
        for (size_t i = 0; i < tokens.size(); i++) {
            std::reverse(tokens[i].begin(), tokens[i].end());
            s += tokens[i];
            if (i != tokens.size() - 1) s += ' ';
        }
        return s;
    }

    void test() {
        CHECK(reverseWords("the sky is blue"), string("blue is sky the"));
        CHECK(reverseWords(""), string(""));
        CHECK(reverseWords(" "), string(""));
        CHECK(reverseWords(" ab "), string("ab"));
        CHECK(reverseWords("  world  "), string("world"));
    }
};
