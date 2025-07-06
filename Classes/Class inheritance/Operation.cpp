//
// Created by ladie on 05/07/2025.
//
#include "Operation.h"

Operation::Operation(int op1, int op2) : op1_(op1), op2_(op2) { }

int Operation::get_op1() const { return op1_; }

int Operation::get_op2() const { return op2_; }