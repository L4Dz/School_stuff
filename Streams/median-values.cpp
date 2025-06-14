//
// Created by ladie on 12/06/2025.
//
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "show_file.h"
using namespace std;

void calc_medians(const string& input_fname, const string& output_fname) {
    ifstream ifs(input_fname);
    if (!ifs.is_open()) {
        return;
    }
    ofstream ofs(output_fname);
    if (!ofs.is_open()) {
        return;
    }

    string line;
    while (getline(ifs, line)) {
        istringstream iss(line);
        vector<double> nums;
        string begin;

        // Read the first word (label/identifier)
        if (!(iss >> begin)) {
            continue; // Skip empty lines
        }

        // Read all numbers from the rest of the line
        double num;
        while (iss >> num) {
            nums.push_back(num);
        }

        // Skip lines with no numbers
        if (nums.empty()) {
            continue;
        }

        // Sort the numbers to find the median
        sort(nums.begin(), nums.end());

        double median;
        if (nums.size() % 2 == 0) {
            // Even number of elements: average of two middle elements
            median = (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2.0;
        } else {
            // Odd number of elements: middle element
            median = nums[nums.size() / 2];
        }

        ofs << begin << " " << fixed<<setprecision(1)<<median << endl;
    }

    ifs.close();
    ofs.close();
}