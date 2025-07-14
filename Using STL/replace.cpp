//
// Created by ladie on 08/07/2025.
//
#include <string>
#include <map>

using namespace std;



void replace(const map<char, char>& r, string& s) {
    for (size_t i=0; i<s.size(); i++) {
        char c = s[i];
        if (r.find(c)!=r.end()) {
            s[i]=r.at(c);
        }
    }
}