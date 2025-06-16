//
// Created by ladie on 13/06/2025.
//
#include "Date3.h"
#include <sstream>
#include <iomanip>
#include <iostream>


Date::Date() : yyyymmdd("00010101") { }



Date::Date(int year, int month, int day) {
    if (year >= 1 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= num_days(year, month)) {
        std::ostringstream oss;
        oss << std::setw(4) << std::setfill('0') << year
            << std::setw(2) << std::setfill('0') << month
            << std::setw(2) << std::setfill('0') << day;
        yyyymmdd = oss.str();
    } else {
        yyyymmdd = "00000000";
    }
}


Date::Date(const std::string& year_month_day) {
    int y, m, d;
    char sep1, sep2;
    std::istringstream iss(year_month_day);
    if ((iss >> y >> sep1 >> m >> sep2 >> d) && sep1 == '/' && sep2 == '/' &&
        y >= 1 && y <= 9999 && m >= 1 && m <= 12 && d >= 1 && d <= num_days(y, m)) {
        std::ostringstream oss;
        oss << std::setw(4) << std::setfill('0') << y
            << std::setw(2) << std::setfill('0') << m
            << std::setw(2) << std::setfill('0') << d;
        yyyymmdd = oss.str();
    } else {
        yyyymmdd = "00000000";
    }
}


int Date::get_year() const {
    if (!is_valid()) return 0;
    return std::stoi(yyyymmdd.substr(0, 4));
}


int Date::get_month() const {
    if (!is_valid()) return 0;
    return std::stoi(yyyymmdd.substr(4, 2));
}


int Date::get_day() const {
    if (!is_valid()) return 0;
    return std::stoi(yyyymmdd.substr(6, 2));
}


bool Date::is_valid() const {
    return yyyymmdd != "00000000";
}


int Date::num_days(int year, int month) {
    static const int days_in_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month < 1 || month > 12) return 0;
    if (month == 2) {
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        return leap ? 29 : 28;
    }
    return days_in_month[month - 1];
}
