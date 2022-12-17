class Solution {
    class Status {
        public:
        ListNode *p;
        bool operator<(const Status &a) const{
            return p->val > a.p->val;
        }
        Status(ListNode* x): p(x) {};
    };
    priority_queue<Status> q;
    ListNode dummy;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto x : lists) {
            if (x) q.push(Status(x));
        }
        ListNode *tail = &dummy;
        while (!q.empty()) {
            Status p = q.top(); q.pop();
            tail->next = p.p;
            if (p.p->next) q.push(p.p->next);
            tail = tail->next;
        }
        return dummy.next;
    }
};
