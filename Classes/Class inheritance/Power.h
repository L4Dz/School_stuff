//
// Created by ladie on 05/07/2025.
//

#ifndef POWER_H
#define POWER_H
#include "Operation.h"

class Power : public Operation {
    public:
    Power(int a, int b);
    int operation() const override;
};

#endif //POWER_H
