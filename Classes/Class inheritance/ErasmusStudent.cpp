//
// Created by ladie on 05/07/2025.
//
#include "ErasmusStudent.h"
#include <string>

using namespace std;

ErasmusStudent::ErasmusStudent(int id, const string& name, const string& course, const string& origin):
Student(id, name, course), origin_(origin) {}

string ErasmusStudent::to_string() const {
    return Student::to_string() + "/" +origin_ + "\n";
}

const string& ErasmusStudent::country() const {
    return origin_;
}