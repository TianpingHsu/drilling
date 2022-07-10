class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        size_t k = 0;
        for (size_t i = 0; i < pushed.size(); i++) {
            s.push(pushed[i]);
            if (s.top() != popped[k]) continue;
            else {
                while (!s.empty() && s.top() == popped[k]) {
                    s.pop();
                    k++;
                }
            }
        }
        return s.empty() && k == popped.size();
    }
};
