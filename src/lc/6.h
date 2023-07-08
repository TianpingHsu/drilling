
#include "inc/utils.h"

class Solution {
public:
    const static int MAX_COLS = 1024;
    bool isValid(const char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '.' || c == ',';
    }
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        char** matrix = new char*[numRows];
        for (size_t i = 0; i < numRows; i++) {
            matrix[i] = new char[s.size()];
            memset(matrix[i], ' ', s.size() * sizeof(char));  // byte-wise
        }
        for (int i = 0, j = 0, p = 0; p < s.size();) {
            while (i < numRows && p < s.size()) {  // down
                matrix[i++][j] = s[p++];
            }
            i = numRows - 2;
            j += 1;
            while (i > 0 && p < s.size()) {  // up
                matrix[i--][++j] = s[p++];
            }
            i = 0;  // reset i
            j += 1;
        }
        string ret;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < s.size(); j++) {
                putchar(matrix[i][j]);
                if (isValid(matrix[i][j])) ret.push_back(matrix[i][j]);
            }
            newline();
        }
        return ret;
    }
#ifdef TEST
    void test() {
        string s;
        {
            s = "PAYPALISHIRING";
            CHECK(convert(s, 4), "PINALSIGYAHRPI");
        }
        {
            s = "PAYPALISHIRING";
            CHECK(convert(s, 3), "PAHNAPLSIIGYIR");
        }
        {
            s = "AB";
            CHECK(convert(s, 1), "AB");
        }
    }
#endif
};

