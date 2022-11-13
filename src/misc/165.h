class Solution {
    vector<string> split(string s) {
        stringstream strs(s);
        string item;
        vector<string> ret;
        while (getline(strs, item, '.')) {
            ret.push_back(item);
        }
        return ret;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1 = split(version1), v2 = split(version2);
        size_t len = std::max(v1.size(), v2.size());
        if (v1.size() != len) {
            for (size_t l = v1.size(); l <= len; l++) v1.push_back("0");
        }
        if (v2.size() != len) {
            for (size_t l = v2.size(); l <= len; l++) v2.push_back("0");
        }
        for (size_t i = 0; i < len; i++) {
            int x = std::stoi(v1[i]), y = std::stoi(v2[i]);
            if (x != y) {
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};
