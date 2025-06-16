//
// Created by ladie on 16/06/2025.
//
#include "Date.h"
#include <iostream>

Date::Date() : year_(1), month_(1), day_(1) {}

Date::Date(int year, int month, int day)
    : year_(year), month_(month), day_(day) {}

bool Date::is_before(const Date& other) const {
    if (year_ != other.year_) return year_ < other.year_;
    if (month_ != other.month_) return month_ < other.month_;
    return day_ < other.day_;
}


