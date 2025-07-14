#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unsigned roman_to_arab(const string& roman) {
    vector<pair<char, unsigned>> roman_to_int = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    // Create a map for fast lookup
    unordered_map<char, unsigned> value_map;
    for (const auto& p : roman_to_int) {
        value_map[p.first] = p.second;
    }

    unsigned total = 0;
    for (size_t i = 0; i < roman.size(); ++i) {
        unsigned atual = value_map[roman[i]];
        unsigned next;
        if (i+1<roman.size()) {

            next = value_map[roman[i+1]];
        }
        else {

            next = 0;
        }

        if (atual < next) {
            total-=atual;
        }
        else {
            total+=atual;
        }

    }
    return total;
}
