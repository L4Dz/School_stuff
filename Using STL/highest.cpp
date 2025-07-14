#include <string>
#include <map>
#include <list>

using namespace std;

string student_highest_avg(map<string, list<int>> m) {
    string best_student;
    double highest_avg = -1.0;

    for (const auto& pair : m) {
        const string& name = pair.first;
        const list<int>& grades = pair.second;

        int sum = 0;
        for (int grade : grades)
            sum += grade;

        double avg = static_cast<double>(sum) / grades.size();

        if (avg > highest_avg) {
            highest_avg = avg;
            best_student = name;
        }
    }

    return best_student;
}
