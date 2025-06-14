#include <iostream>
#include <iomanip>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void print_grades(const map<string, list<int>>& grades) {
    // Vector of pairs to hold name and average
    vector<pair<string, double>> student_averages;
    double total_avg_sum = 0.0;

    // Calculate average for each student
    for (const auto& entry : grades) {
        const string& name = entry.first;
        const list<int>& scores = entry.second;

        double sum = 0.0;
        for (int score : scores) {
            sum += score;
        }
        double avg = scores.empty() ? 0.0 : sum / scores.size();
        student_averages.push_back({name, avg});
        total_avg_sum += avg;
    }

    // Sort by decreasing average
    sort(student_averages.begin(), student_averages.end(),
         [](const pair<string, double>& a, const pair<string, double>& b) {
             return a.second > b.second;
         });

    // Print each student
    cout << fixed << setprecision(2);
    for (const auto& entry : student_averages) {
        cout << entry.first << " " << entry.second << endl;
    }

    // Print overall average of averages
    double overall_avg = student_averages.empty() ? 0.0 : total_avg_sum / student_averages.size();
    cout << overall_avg << endl;
}

