#include "utils.h"
class LRUCache {
    struct Status {
        long long int time;
        int key;
        int val;
        Status() {}
        Status(long long int t, int k, int v): time(t), key(k), val(v) {}
        Status(const Status &s) {time = s.time, key = s.key, val = s.val;}
    };
    unordered_map<int, Status> kvs;
    int cap;
    long long int cur_time;
public:
    LRUCache(int capacity) {
        cur_time = 0;
        cap = capacity;
    }
    
    int get(int key) {
        cur_time++;
        if (kvs.find(key) != kvs.end()) {
            Status s = kvs[key];
            return s.val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        cur_time++;
        if (kvs.find(key) == kvs.end()) {
            kvs[key] = Status(cur_time, key, value);
            if (kvs.size() > cap) {
                Status kv = kvs[key];
                for (auto it = kvs.begin(); it != kvs.end(); it++) {
                    if (kv.time > it->second.time) kv = (it->second);
                }
                kvs.erase(kv.key);
            }
        } else {
            kvs[key].time = cur_time;
            kvs[key].val = value;
        }
    }

    void content() {
        cout << "{\n";
        for (auto it = kvs.begin(); it != kvs.end(); it++) {
            cout << it->first << " : ";
            Status& s = it->second;
            cout << s.val << "  [" << s.time <<"]" << endl;
        }
        cout << "}\n";
    }
};
class Solution {
    public:
        void test() {
            LRUCache lru(2);
            lru.put(1, 1); 
            lru.content();
            lru.put(2, 2);
            lru.content();
            CHECK_INT(lru.get(1), 1);
            lru.put(3, 3);
            lru.content();
            CHECK_INT(lru.get(2), -1);
            lru.put(4, 4);
            lru.content();
            CHECK_INT(lru.get(1), -1);
            CHECK_INT(lru.get(3), 3);
            CHECK_INT(lru.get(4), 4);
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
 struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/lru-cache/solution/lruhuan-cun-ji-zhi-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

 /*
  *
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
        cache->put(1, 1);
        cache->put(2, 2);
        OUT(cache->get(1));
        cache->put(3, 3);
        OUT(cache->get(2));
        cache->put(4, 4);
        OUT(cache->get(1));
        OUT(cache->get(3));
        OUT(cache->get(4));
        delete cache;
    }
#endif
};
*/

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
