//
// Created by ladie on 05/07/2025.
//

#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <string>
using namespace std;

class Student: public Person {
public:
    Student(int id, const string& name, const string& course);
    const string& course() const;
    virtual std::string to_string() const override;
protected:
    string course_;
};




#endif //STUDENT_H
