//
// Created by ladie on 10/06/2025.
//
#include <string>
#include <vector>
#include "print_string.h"
using namespace std;

//não fui eu que fiz esse tenho de refazer depois

void split(const string& s, vector<string>& v) {
    v.clear(); // Clear the vector first

    size_t start = 0;
    size_t end = 0;

    while (end != string::npos) {
        // Skip leading spaces
        start = s.find_first_not_of(' ', start);
        if (start == string::npos) break; // No more non-space characters

        // Find the end of current word
        end = s.find(' ', start);

        // Extract the word
        if (end == string::npos) {
            // Last word (no space after it)
            v.push_back(s.substr(start));
            break;
        } else {
            // Word followed by space
            v.push_back(s.substr(start, end - start));
            start = end + 1;
        }
    }
}