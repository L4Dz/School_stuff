//
// Created by ladie on 05/07/2025.
//

#ifndef ERASMUSSTUDENT_H
#define ERASMUSSTUDENT_H


#include "Student.h"
#include <string>
using namespace std;

class ErasmusStudent : public Student {
public:
    ErasmusStudent(int id, const string& name, const string& course, const string& origin);
    string to_string() const override;

    const string &country() const;

protected:
    string origin_;
};




#endif //ERASMUSSTUDENT_H
