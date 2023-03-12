
#pragma once

#include <string>
#include <queue>
#include <list>

template<class T>
class Trie {
    private:
        const static int ALPHABET_TABLE_SIZE = 256;  // ascii code
        class Node {
            public:
                Node() {
                    for (int i = 0; i < ALPHABET_TABLE_SIZE; i++) {
                        next[i] = nullptr;
                    }
                }
                Node(const T& val) {
                    pval = new T;
                    *pval = val;
                    for (int i = 0; i < ALPHABET_TABLE_SIZE; i++) {
                        next[i] = nullptr;
                    }
                }
                ~Node() {
                    if (pval) delete pval;
                    for (int i = 0; i < ALPHABET_TABLE_SIZE;i ++)
                        if (next[i]) delete next[i];
                }
            private:
                T* pval = nullptr;
                Node* next[ALPHABET_TABLE_SIZE];
        };
    public:
        Trie() = default;
        ~Trie() = default;

        void put(const std::string& key, const T& val) {
           _put(&root, key, 0, val); 
        }

        const T* get(const std::string& key) const {
            return _get(&root, key, 0);
        }

    private:
        void _put(Node* proot, const std::string& key, int idx, const T& val) {
            if (!proot->next[key[idx]]) proot->next[key[idx]] = new Node;
            if (idx == key.size() - 1) {
                proot->next[key[idx]]->pval = new T(val);
                return;
            }
            _put(proot->next[key[idx]], key, idx + 1, val);
        }

        const T* _get(Node* proot, const std::string& key, int idx) const {
            if (!root) return nullptr;
            if (idx == key.size() - 1) return proot->pval;
            return _get(proot->next[key[idx]], key, idx+1);
        }

    private:
        Node root;
};

