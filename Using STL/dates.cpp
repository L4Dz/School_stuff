#include "Date.h"
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// Comparação para sort
bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.getYear() != rhs.getYear())
        return lhs.getYear() < rhs.getYear();
    if (lhs.getMonth() != rhs.getMonth())
        return lhs.getMonth() < rhs.getMonth();
    return lhs.getDay() < rhs.getDay();
}

// Impressão no formato YYYY/MM/DD
std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << std::setw(4) << std::setfill('0') << d.getYear() << '/'
       << std::setw(2) << std::setfill('0') << d.getMonth() << '/'
       << std::setw(2) << std::setfill('0') << d.getDay();
    return os;
}
