#include "Person.h"
#include <iostream>

Person::Person() : name_("NO_NAME"), birth_date_() {}

Person::Person(const std::string& name, const Date& birth_date)
    : name_(name), birth_date_(birth_date) {}

std::string Person::get_name() const {
    return name_;
}

Date Person::get_birth_date() const {
    return birth_date_;
}


