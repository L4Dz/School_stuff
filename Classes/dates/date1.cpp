#include "Date1.h"
#include <iostream>
#include <iomanip>

Date::Date() : Date(1, 1, 1) {}

Date::Date(int year, int month, int day)
    : year(year), month(month), day(day) {}

int Date::get_day() const { return day; }

int Date::get_month() const { return month; }

int Date::get_year() const { return year; }



bool is_before(const Date& date1, const Date& date2) {
    if (date1.get_year() != date2.get_year())
        return date1.get_year() < date2.get_year();
    if (date1.get_month() != date2.get_month())
        return date1.get_month() < date2.get_month();
    return date1.get_day() < date2.get_day();
}

