

#include "inc/utils.h"

class Solution {
    static bool is_greater(const string &a, const string& b) {
        //show(vector<string>{a, b});
        if (a.size() == b.size()) return a > b;
        int i = 0;
        while (i < a.size() && i < b.size()) {
            if (a[i] != b[i]) return a[i] > b[i];
            i++;
        }
        if (i == a.size() && i < b.size()) {
            return is_greater(a, b.substr(a.size(), b.size()));
        } 
        if (i == b.size() && i < a.size()) {
            return is_greater(a.substr(b.size(), a.size()), b);
        }
        return false;
    }

    bool all0(const string &s) {
        for (auto x : s) if (x != '0') return false;
        return true;
    }

public:
    string largestNumber(vector<int>& nums) {
        string ret;
        vector<string> v;
        for (auto x : nums) {
            v.push_back(to_string(x));
        }
        sort(v.begin(), v.end(), is_greater);
        for (auto x : v) ret += x;
        if (all0(ret)) return "0";
        return ret;
    }

#ifdef TEST
    void test() {
        {
            //auto v = createVector("[10,2]");
            //std::string ret = largestNumber(v);
            //CHECK(ret, "210");
        }

        {
            //auto v = createVector("[3,30,34,5,9]");
            //std::string ret = largestNumber(v);
            //CHECK(ret, "9534330");
        }
        {
            auto v = createVector("[999999991,9]");
            std::string ret = largestNumber(v);
            CHECK(ret, "9999999991");
        }
    }
#endif
};

/*
 class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ss;
        bool all0 = true;
        for (auto x : nums) {
            ss.push_back(std::to_string(x));
            if (x != 0) all0 = false;
        }
        if (all0) return "0";
        std::sort(ss.begin(), ss.end(), [](const string &s1, const string &s2) {
            if (s1.size() == s2.size()) return s1 > s2;
            return s1 + s2 > s2 + s1;
        });
        string ret;
        for (auto x : ss) ret += x;
        return ret;
    }
};
 */
