//
// Created by ladie on 05/07/2025.
//
#include "Sum.h"

Sum::Sum(int a, int b) : Operation(a, b) {}
int Sum::operation() const {
    return get_op1()+get_op2();
}

