#include <iostream>
#include <fstream>
#include <string>
#include "show_file.h"

using namespace std;

void word_count(const string& input_fname, const string& output_fname) {
    ifstream infile(input_fname);
    ofstream outfile(output_fname);

    if (!infile || !outfile) {
        cerr << "Error opening file(s)." << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        int count = 0;
        bool in_word = false;

        for (char c : line) {
            if (c != ' ') {
                if (!in_word) {
                    count++;
                    in_word = true;
                }
            } else {
                in_word = false;
            }
        }

        outfile << count << '\n';
    }
}
