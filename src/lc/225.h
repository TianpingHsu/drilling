class MyStack {
    queue<int> a, b;
public:
    MyStack() {

    }
    
    void push(int x) {
        if (a.empty()) {
            a.push(x);
            while (!b.empty()) {
                a.push(b.front());
                b.pop();
            }
        } else {
            b.push(x);
            while (!a.empty()) {
                b.push(a.front());
                a.pop();
            }
        }
    }
    
    int pop() {
        auto x = top();
        if (a.empty()) b.pop();
        else a.pop();
        return x;
    }
    
    int top() {
        if (a.empty()) return b.front();
        return a.front();
    }
    
    bool empty() {
        return a.empty() && b.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
