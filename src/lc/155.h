
#include "inc/utils.h"

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        a.push(val);
        if (b.empty())
            b.push(val);
        else {
            b.push(min(val, b.top()));
        }
    }

    void pop() {
        a.pop();
        b.pop();
    }

    int top() {
        return a.top();
    }

    int getMin() {
        return b.top();
    }
private:
    stack<int> a, b;
};

class Solution {
    public:
        void test() {
            MinStack s;
            s.push(-2);
            CHECK(s.getMin(), -2);
            s.push(0);
            CHECK(s.getMin(), -2);
            s.push(-3);
            CHECK(s.getMin(), -3);
        }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
