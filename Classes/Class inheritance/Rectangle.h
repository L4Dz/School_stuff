//
// Created by ladie on 06/07/2025.
//



#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(const point& center, double width, double height);
    double area() const override;
    double perimeter() const override;
    bool contains(const point& p) const override;
protected:
    double width_;
    double height_;
};






#endif //RECTANGLE_H
