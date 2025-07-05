#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Template class Pair
template <typename T1, typename T2>
class Pair {
private:
    T1 first_;
    T2 second_;

public:
    // Constructor
    Pair(const T1& first, const T2& second) : first_(first), second_(second) {}

    // Getters
    T1 get_first() const { return first_; }
    T2 get_second() const { return second_; }

    // Show single pair
    void show() const {
        std::cout << "{" << first_ << "," << second_ << "}";
    }
};

// Function to show a vector of Pair<string, int>
void show(const std::vector<Pair<std::string, int>>& vec) {
    std::cout << "{";
    for (const auto& p : vec) {
        p.show();
    }
    std::cout << "}";
}


// Sorting by first_ (string)
void sort_by_first(std::vector<Pair<std::string, int>>& vec) {
    std::sort(vec.begin(), vec.end(),
              [](const Pair<std::string, int>& a, const Pair<std::string, int>& b) {
                  return a.get_first() < b.get_first();
              });
}

// Sorting by second_ (int)
void sort_by_second(std::vector<Pair<std::string, int>>& vec) {
    std::sort(vec.begin(), vec.end(),
              [](const Pair<std::string, int>& a, const Pair<std::string, int>& b) {
                  return a.get_second() < b.get_second();
              });
}

// Optional: for local testing
/*
int main() {
    std::vector<Pair<std::string, int>> people = {
        {"Maria", 17}, {"Ana", 21}, {"Pedro", 19}
    };

    sort_by_first(people);
    show(people);
    std::cout << '\n';

    sort_by_second(people);
    show(people);
    std::cout << '\n';

    return 0;
}
*/
