//
// Created by ladie on 10/06/2025.
//

#include <string>
#include <vector>

using namespace std;

string longest_prefix(const vector<string>& v) {
    string prefix="";
    for (size_t i = 0; i < v[0].size(); i++) {
        char c = v[0][i];
        for (const string &s: v) {
            if (s.size() - 1 < i) {
                return prefix;
            }
            if (s[i] != c) {
                return prefix;
            }
        }
        prefix += c;
    }
    return prefix;
}
