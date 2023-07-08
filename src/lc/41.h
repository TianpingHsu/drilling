
#include "inc/utils.h"
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (qa.size() == 0) {
            qa.push(num);
        } else {
            if (qa.top() > num) {
                qb.push(num);
            } else {
                qa.push(num);
            }
            if (qa.size() < qb.size()) {
                qa.push(qb.top());
                qb.pop();
            } else if (qa.size() > qb.size() + 1) {
                qb.push(qa.top());
                qa.pop();
            }
        }
    }
    
    double findMedian() {
        if (qa.size() == qb.size() + 1) return qa.top();
        else return (qa.top() + qb.top()) / 2.0;
    }

private:
    int size() { return qa.size() + qb.size(); }
private:
    /*
     * for all elements in qa are greater than or equal to ones in qb;
     * qb.size() <= qa.size() <= qb.size() + 1
     * then we will have:
     * if qa.size() == qb.size() + 1:
     *      qa.top() is the median
     * else:
     *      (qa.top() + qb.top()) / 2.0 is the median
     */
    priority_queue<int, vector<int>, std::greater<int>> qa;
    priority_queue<int, vector<int>, std::less<int>> qb;
};

class Solution {
public:
#ifdef TEST
    void test() {
        MedianFinder mf;
        mf.addNum(2);
        CHECK(mf.findMedian(), 2);
        mf.addNum(3);
        CHECK(mf.findMedian(), 2.5);
        mf.addNum(4);
        CHECK(mf.findMedian(), 3);
    }
#endif
};

