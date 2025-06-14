#include <fstream>
#include <string>
#include <algorithm> // for transform
#include <cctype>    // for tolower

using namespace std;

string to_lowercase(const string& s) {
    string result = s;
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] = tolower(result[i]);
    }
    return result;
}

int count(const string& fname, const string& word) {
    ifstream fin(fname);
    if (!fin) return 0;

    string w;
    int total = 0;
    string lower_word = to_lowercase(word);

    while (fin >> w) {
        if (to_lowercase(w) == lower_word) {
            total++;
        }
    }

    return total;
}
