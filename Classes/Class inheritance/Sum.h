//
// Created by ladie on 05/07/2025.
//

#ifndef SUM_H
#define SUM_H

#include "Operation.h"

class Sum : public Operation {

    public:
    Sum(int a, int b);
    int operation() const override;
};

#endif //SUM_H
