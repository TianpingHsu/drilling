
#include <string>
#include <queue>

unsigned int ip2int(const std::string ip) {
    unsigned int x = 0;
    std::queue<unsigned int> q;
    size_t i = ip.size() - 1;
    while (i < ip.size()) {
        int s = 0;
        while (i < ip.size() && ip[i] != '.') {
            s = 10 * s + ip[i] - '0';
            i++;
        }
        q.push(s);
        i++;
    }
    while (!q.empty()) {
        x = x * 256 + q.front();
        q.pop();
    }
    return x;
}

