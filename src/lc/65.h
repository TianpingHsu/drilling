
#include "inc/utils.h"

class Solution {
public:
    Solution(): transition_table {
        {{S_0, SPACE}, S_0},
        {{S_0, DIGIT}, S_1},
        {{S_0, SIGN},  S_3},
        {{S_0, DOT},   S_2},
        {{S_1, DIGIT}, S_1},
        {{S_1, SPACE}, S_8},
        {{S_1, EXP},   S_5},
        {{S_1, DOT},   S_4},
        {{S_2, DIGIT}, S_4},
        {{S_3, DIGIT}, S_1},
        {{S_3, DOT},   S_2},
        {{S_4, DIGIT}, S_4},
        {{S_4, EXP},   S_5},
        {{S_4, SPACE}, S_8},
        {{S_5, DIGIT}, S_7},
        {{S_5, SIGN},  S_6},
        {{S_6, DIGIT}, S_7},
        {{S_7, DIGIT}, S_7},
        {{S_7, SPACE}, S_8},
        {{S_8, SPACE}, S_8},
    }
    {}
    bool isNumber(string s) {
        m_currentState = S_0;
        for (auto c : s) {
            if (transition_table.contains({m_currentState, event(c)})) {
                m_currentState = transition_table[{m_currentState, event(c)}];
            } else {
                return false;
            }
        }
        return m_currentState == S_1
            || m_currentState == S_4
            || m_currentState == S_7
            || m_currentState == S_8;
    }
    enum STATE {
        S_0,
        S_1,
        S_2,
        S_3,
        S_4,
        S_5,
        S_6,
        S_7,
        S_8,
    };
    enum EVENT {
        SIGN,
        DIGIT,
        DOT,
        EXP,
        SPACE,
        UNKNOWN,
    };
    enum EVENT event(const char c) {
        if (c == '+' || c == '-') return SIGN;
        if (c >= '0' && c <= '9') return DIGIT;
        if (c == 'e' || c == 'E') return EXP;
        if (c == '.') return DOT;
        if (c == ' ') return SPACE;
        return UNKNOWN;
    }

   enum STATE m_currentState = S_0; 
   map<pair<enum STATE, enum EVENT>, enum STATE> transition_table;


#ifdef TEST
public:
    void test() {
        vector<string> v = {"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
        for (auto s : v) {
            CHECK(isNumber(s), true);
            cout << "input: " << s << " state: " << m_currentState << endl;
        }
        v = {"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"};
        for (auto s : v) {
            CHECK(isNumber(s), false);
        }
    }
#endif
};

