//
// Created by ladie on 05/07/2025.
//
#include "Student.h"

#include <string>
using namespace std;

Student::Student(int id, const string &name, const string &course) : Person(id, name), course_(course) {}

string Student::to_string() const {
    return Person::to_string() + "/" + course_;
}

 const string &Student::course() const {
    return course_;
}


