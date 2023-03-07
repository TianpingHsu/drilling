
#include "kmp.h"

int main() {
    std::string txt, pat;
    {
        txt = "this is a test text";
        pat = "test";
        KMP kmp(pat);
        printf("search result: %d\n", kmp.search(txt));
    }

    {
        txt = "AABAACAADAABAABA";
        pat = "AABA";
        KMP kmp(pat);
        printf("search result: %d\n", kmp.search(txt));
    }
}

