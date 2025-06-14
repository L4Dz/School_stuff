//
// Created by ladie on 12/06/2025.
//
#include <fstream>
#include <string>
#include <iomanip>
#include "show_file.h"
using namespace std;

void maximum(const string& input_fname, const string& output_fname) {
    ifstream ifs(input_fname);
    if (!ifs.is_open()) {
        return;
    }
    ofstream ofs(output_fname);
    if (!ofs.is_open()) {
        return;
    }
    int count = 0;
    double max = -1001;
    double num;
    while ((ifs >> num)) {
        count++;
        if (max < num) {
            max = num;
        }
        ofs << fixed<<setprecision(3) << num<< endl;
    }
    ofs<<"count="<<count<<"/max="<<fixed<<setprecision(3)<<max<<endl;
    ofs.close();
    ifs.close();
}