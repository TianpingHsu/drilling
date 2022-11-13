#include "utils.h"
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for (auto x : s) {
            if (x == '(' || x == '{' || x == '[') parentheses.push(x);
            else {
                if (parentheses.empty()) return false;
                char y = parentheses.top();
                if ((y == '(' && x == ')') 
                || (y == '{' && x == '}')
                || (y == '[' && x == ']')
                ) {
                    parentheses.pop();
                } else {
                    return false;
                }
            }
        }
        return parentheses.empty();
    }
    void test() {

    }
}; 
