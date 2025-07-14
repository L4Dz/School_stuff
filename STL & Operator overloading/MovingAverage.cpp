//
// Created by ladie on 08/07/2025.
//
#include "MovingAverage.h"

MovingAverage::MovingAverage(std::size_t n): n_(n){};

void MovingAverage::update(double value) {
    if (values_.size()+1<=n_) {
        values_.push_back(value);
    }
    else {
        values_.pop_front();
        values_.push_back(value);
    }
}

double MovingAverage::get() const {
    double sum = 0;
    double v=0;
    for (double atual : values_) {
        sum += atual;
        v += 1;
    }
    return sum/v;
}
