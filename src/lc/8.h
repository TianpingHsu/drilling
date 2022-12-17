#include "utils.h"
class FSM {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    
    string next_state(string current_state, char event) {
        vector<string> &states = table[current_state];
        int idx = 0;
        if (event == ' ') {
            idx = 0;
        } else if (event == '+' || event == '-') {
            idx = 1;
        } else if (event >= '0' && event <= '9') {
            idx = 2;
        } else {
            idx = 3;
        }
        return states[idx];
    }
public:
    int sign = 1;
    long long ans = 0;

    void parse(char event) {
        state = next_state(state, event);
        if (state == "in_number") {
            ans = ans * 10 + event - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        } else if (state == "signed") {
            sign = (event == '+' ? 1 : -1);
        }
    }
};

class Solution {
public:
    int myAtoi(string s) {
        FSM fsm;
        for (auto x : s) fsm.parse(x);
        return fsm.sign * fsm.ans;
    }
    void test() {
        cout << myAtoi("   +1234 dlkfjklasdflk") << endl;
    }
};
