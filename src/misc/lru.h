#include "utils.h"
class LRUCache {
    struct Node {
        union {
            struct {
                Node *pre, *next;
            };
            struct {
                Node* head, *tail;
            };
        };
        int key, value;
    };

    Node dummy;

    void init() {
        dummy.head = &dummy;
        dummy.tail = &dummy;
    }

    void push_front(Node *node) {
        if (!node) return;
        if (dummy.head == &dummy && dummy.tail == &dummy) {
            push_back(node);        
        } else {
            node->next = dummy.head;
            node->pre = &dummy;
            dummy.head->pre = node;
            dummy.head = node;
        }
    }

    void push_back(Node* node) {
        if (dummy.head == &dummy && dummy.tail == &dummy) {
            // empty
            node->pre = &dummy;
            node->next = &dummy;
            dummy.head = node;
            dummy.next = node;
        } else {
            Node* tail = dummy.tail;
            node->pre = tail;
            node->next = &dummy;
            tail->next = node;
            dummy.tail = node;
        }
    }

    Node* erase_node(Node* node) {
        if (!node) return NULL;
        if (node->pre == &dummy && node->next == &dummy) {
            dummy.head = &dummy;
            dummy.tail = &dummy;
            node->pre = NULL;
            node->next = NULL;
            return node;
        }
        if (dummy.head == node) {
            Node* next = node->next;
            dummy.head = next;
            next->pre = &dummy;
            node->pre = NULL;
            node->next = NULL;
            return node;
        }
        if (dummy.tail = node) {
            Node *pre = node->pre;
            pre->next = &dummy;
            dummy.tail = pre;
            node->pre = NULL;
            node->next = NULL;
            return node;
        }
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->pre = NULL;
        node->next = NULL;
        return node;
    }

    map<int,Node*> table;
    int cap = 0;
    public:
    LRUCache(int capacity) {
        cap = capacity;
        init();
    }

    int get(int key) {
        if (table.find(key) == table.end()) return -1;
        Node *node = table[key];
        erase_node(node);
        push_front(node);
        return node->value;
    }

    void put(int key, int value) {
        if (table.find(key) != table.end()) {
            Node *node = table[key];
            node->value = value;
            erase_node(node);
            push_front(node);
        } else {
            if (table.size() == cap) {
                Node *tail = dummy.tail;
                erase_node(dummy.tail);
                table.erase(tail->key);
                delete tail;
            }
            Node *node = new Node;
            node->key = key;
            node->value = value;
            push_front(node);
            table[key] = node;
        }
    }
};
class Solution {
    public:   
        void test() {
            LRUCache *obj = new LRUCache(2);
            obj->put(1, 1);
            obj->put(2, 2);
            cout << obj->get(1) << endl;
            obj->put(3, 3);
            cout << obj->get(2) << endl;
            obj->put(4, 4);
            cout << obj->get(1) << endl;
            cout << obj->get(3) << endl;
            cout << obj->get(4) << endl;
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
