//
// Created by ladie on 12/06/2025.
//
#include <sstream>
#include <fstream>
#include <string>
#include <cctype>
#include "print.h"
using namespace std;

int is_line_empty(string s) {
    if (s.empty()) {
        return 1;
    }
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            return 0;
        }
    }
    return 1;

}

void remove_leading_and_trailing(string& s) {
    size_t start, end;
    start = s.find_first_not_of(' ');
    end = s.find_last_not_of(' ');
    if (end == string::npos) {
        end = s.size();
    }
    s=s.substr(start, end - start + 1);
}


void toupper(std::string& s) {
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = std::toupper(s[i]);
    }
}


void normalise(const string& input_fname, const string& output_fname) {
    ifstream file_in(input_fname);
    if (!file_in) {
        return;
    }
    ofstream file_out(output_fname);
    if (!file_out) {
        return;
    }
    string line;
    while (getline(file_in, line)) {
        int is = is_line_empty(line);
        if (is!=0) {
            continue;

        }
        remove_leading_and_trailing(line);
        toupper(line);
        file_out << line << endl;



    }
    file_out.close();
    file_in.close();
}
