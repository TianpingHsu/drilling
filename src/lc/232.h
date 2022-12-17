class MyQueue {
    stack<int> queue, back;
public:
    MyQueue() {

    }
    
    void push(int x) {
        back.push(x);
    }
    
    int pop() {
        if (queue.empty()) {
            while (!back.empty()) {
                int x = back.top();
                back.pop();
                queue.push(x);
            }
        }
        int x = queue.top();
        queue.pop();
        return x;
    }
    
    int peek() {
        if (queue.empty()) {
            while (!back.empty()) {
                int x = back.top();
                back.pop();
                queue.push(x);
            }
        }
        int x = queue.top();
        return x;
    }
    
    bool empty() {
        return queue.empty() && back.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
