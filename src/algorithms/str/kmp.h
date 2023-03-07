
#include <string>
#include <vector>
#include <cstring>

class KMP {
    public:
        explicit KMP(const std::string& pattern): pat(pattern), dfa(nullptr) {
            if (!pat.empty()) {
                dfa = new unsigned int*[pat.size()];
                for (size_t i = 0; i < pat.size(); i++) 
                    dfa[i] = new unsigned int[ALPHABET_TABLE_SIZE];
                memset(dfa[0], 0, sizeof(int) * pat.size() * ALPHABET_TABLE_SIZE);
                buildDFA();
            }
        }

        ~KMP() {}

        int search(const std::string& txt) {
            for (int X = 0, i = 0; i < txt.size(); i++) {
                X = dfa[X][txt[i]];  // update X
                if(X == pat.size()) return i - pat.size() + 1;
            }
            return -1;
        }

    private:
        void buildDFA() {
            dfa[0][pat[0]] = 1;  // base case
            for (int X = 0, i = 1; i < pat.size(); i++) {
                for (int c = 0; c < ALPHABET_TABLE_SIZE; c++)  // for each char in ascii code table
                    dfa[i][c] = dfa[X][c];
                dfa[i][pat[i]] = i + 1;  // match, go next
                X = dfa[X][pat[i]];  // update restart state, note that X <= i always keeps
            }
        }

    private:
        const static int ALPHABET_TABLE_SIZE = 256;  // ascii code table
        std::string pat;
        unsigned int **dfa = nullptr;
};

