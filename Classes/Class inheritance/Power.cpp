//
// Created by ladie on 05/07/2025.
//
#include "Power.h"


Power::Power(int a, int b) : Operation(a, b) {}

int Power::operation() const {
    if (get_op2()==0) {
        return 1;
    }
    if (get_op2()<0) {
        return 1/get_op1();
    }
    int result = get_op1();
    for (int i = 1; i < get_op2(); i++) {
        result *= get_op1();
    }
    return result;
}
