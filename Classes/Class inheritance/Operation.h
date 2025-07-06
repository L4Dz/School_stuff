//
// Created by ladie on 05/07/2025.
//

#ifndef __Operation_h__
#define __Operation_h__

class Operation {
    int op1_, op2_; // two operands

public:
    Operation(int op1, int op2);

    virtual ~Operation() = default;

    int get_op1() const;

    int get_op2() const;

    virtual int operation() const = 0; // operation
};

#endif

