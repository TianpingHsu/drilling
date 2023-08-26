

#include "inc/utils.h"

struct CListNode {
    struct CListNode *pre, *next;
    int k, v;
    CListNode() {
        pre = nullptr;
        next = nullptr;
        k = -1;
        v = -1;
    }
    CListNode(int kk, int vv) {
        pre = nullptr;
        next = nullptr;
        k = kk;
        v = vv;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        dummy.pre = &dummy;
        dummy.next = &dummy;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            CListNode* p = m[key];
            int ret = p->v;
            p->pre->next = p->next;
            p->next->pre = p->pre;
            p->next = dummy.next;
            p->pre = &dummy;
            dummy.next->pre = p;
            dummy.next = p;
            return ret;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {  // exists
            CListNode* p = m[key];
            p->v = value;  // update
            // delete from list
            CListNode *pre = p->pre;
            CListNode *next = p->next;
            pre->next = next;
            next->pre = pre;
            // insert front
            insertFront(p);

            return;
        }
        // insert front
        CListNode *p = new CListNode(key, value);
        m[key] = p;  // cache it
        insertFront(p);
        if (++size > cap) {
            evicate();
            size--;
        }
    }

private:
    CListNode dummy;
    map<int, CListNode*> m;
    int cap, size;

    void evicate() {
        CListNode *p = dummy.pre;  // get last element
        CListNode *q = p->pre;  // get last second element
        dummy.pre = q;
        q->next = &dummy;
        m.erase(p->k);
        delete p;
    }

    void insertFront(CListNode* p) {
        dummy.next->pre = p;
        p->next = dummy.next;
        dummy.next = p;
        p->pre = &dummy;
    }
};

class Solution {
public:
#ifdef TEST
    void test() {
        LRUCache *cache = new LRUCache(2);
        cache->put(2, 1);
        cache->put(1, 1);
        cache->put(2, 3);
        cache->put(4, 1);
        OUT(cache->get(1));
        OUT(cache->get(2));
        /*
        cache->put(1, 1);
        cache->put(2, 2);
        OUT(cache->get(1));
        cache->put(3, 3);
        OUT(cache->get(2));
        cache->put(4, 4);
        OUT(cache->get(1));
        OUT(cache->get(3));
        OUT(cache->get(4));
        */
        delete cache;
    }
#endif
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
