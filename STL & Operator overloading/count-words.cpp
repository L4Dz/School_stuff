//
// Created by ladie on 07/07/2025.
//
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

void show_vector(const vector<pair<string, size_t>>& count) {
    std::cout << "[ ";
    for (const auto& e : count) {
        std::cout << e.first << ":" << e.second << ' ';
    }
    std::cout << "]\n";
}

void to_lower(string& s) {
    for (auto& c : s) {
        c = tolower(c);
    }
}

void count_words(const string& str, vector<pair<string, size_t>>& count) {



    map<string, size_t> map;

    istringstream iss(str);

    string word;

    while (iss >> word) {
        to_lower(word);
        if (map.find(word) == map.end()) {//map.find é pra encontrar, map.end() é o iterador final ou
            //seja n chegou até la
            map.insert(pair<string, size_t>(word, 1));
        }
        else {
            map[word]++;
        }
    }

    for (auto it = map.begin(); it != map.end(); it++) {
        count.push_back(make_pair(it->first, it->second));
    }

}