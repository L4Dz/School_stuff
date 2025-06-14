//
// Created by ladie on 12/06/2025.
//
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "wc.h"
using namespace std;

wcresult wc(const string& filename) {
    ifstream ficheiro(filename);
    if (!ficheiro) {
        cerr << "Can't open file " << filename << endl;
        return {0, 0, 0};
    }

    string line;
    unsigned int words = 0, lines = 0, bytes = 0;

    while (getline(ficheiro, line)) {
        lines++;
        bytes += line.length() + 1;


        stringstream ss(line);
        string word;
        while (ss >> word) {
            words++;
        }
    }


    ficheiro.close();
    wcresult result = {lines, words, bytes};
    return result;
}