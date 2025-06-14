//
// Created by ladie on 13/06/2025.
//
#include "Date2.h"
#include <sstream>


using namespace std;

//quero ainda fazer uma review na cena do static pra ver bem oq é e como funciona e para oq serve

Date::Date() : Date(1, 1, 1) {}

Date::Date(int y, int m, int d) {
    if (y >= 1 && y <= 9999 && m >= 1 && m <= 12 && d >= 1 && d <= num_days(y, m)) {
        year = y;
        month = m;
        day = d;
    } else {
        year = month = day = 0;
    }
}

Date::Date(const std::string& year_month_day) {
    char sep1, sep2;
    std::istringstream iss(year_month_day);
    int y, m, d;
    if ((iss >> y >> sep1 >> m >> sep2 >> d) && sep1 == '/' && sep2 == '/') {
        if (y >= 1 && y <= 9999 && m >= 1 && m <= 12 && d >= 1 && d <= num_days(y, m)) {
            year = y;
            month = m;
            day = d;
        } else {
            year = month = day = 0;
        }
    } else {
        year = month = day = 0;
    }
}



int Date::get_day() const { return day; }

int Date::get_month() const { return month; }

int Date::get_year() const { return year; }

bool Date::is_valid() const {
    return year != 0 && month != 0 && day != 0;
}

int Date::num_days(int y, int m) {
    static const int days_in_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (m < 1 || m > 12) return 0;
    if (m == 2) {
        bool leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        return leap ? 29 : 28;
    }
    return days_in_month[m - 1];
}



