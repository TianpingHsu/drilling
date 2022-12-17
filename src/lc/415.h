#include "utils.h"

class Solution {
    int digit2int(char c) {
        return c - '0';
    }
    char int2digit(int x) {
        return '0' + x;
    }
    int addChar(char c1, char c2, int carry) {
        return digit2int(c1) + digit2int(c2) + carry;
    }
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ret;
        size_t i = 0, carry = 0;
        while (i < num1.size() && i < num2.size()) {
            int tmp = addChar(num1[i], num2[i], carry);
            carry = tmp / 10;
            tmp %= 10;
            ret += int2digit(tmp);
            i++;
        }
        while (i < num1.size()) {
            int tmp = addChar(num1[i], '0', carry);
            carry = tmp / 10;
            tmp %= 10;
            ret += int2digit(tmp);
            i++;
        }
        while (i < num2.size()) {
            int tmp = addChar(num2[i], '0', carry);
            carry = tmp / 10;
            tmp %= 10;
            ret += int2digit(tmp);
            i++;
        }
        if (carry) ret += int2digit(carry);
        reverse(ret.begin(), ret.end());
        return ret;
    }
    void test() {
        CHECK(addStrings("11", "123"), "1341");
    }
};
