//
// Created by ladie on 08/07/2025.
//
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

void to_lower(string &s) {
    for (size_t i=0; i<s.length(); i++) {
        s[i] = tolower(s[i]);
    }
}

void count_words(const string& str, map<string, size_t>& count) {
    istringstream ss(str);
    string word;
    while (ss>>word) {
        to_lower(word);
        if (count.find(word) == count.end()) {
            count[word] = 1;
        }
        else {
            count[word]++;
        }
    }
}

void show_map(const map<string, size_t>& count) {
    std::cout << "[ ";
    for (const auto& e : count) {
        std::cout << e.first << ":" << e.second << ' ';
    }
    std::cout << "]\n";
}