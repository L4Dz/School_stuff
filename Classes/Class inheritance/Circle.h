//
// Created by ladie on 06/07/2025.
//

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
    public:
    Circle(const point& center, double radius);
    double area() const override;
    double perimeter() const override;
    bool contains(const point &p) const override;
    protected:
    double radius_;

};





#endif //CIRCLE_H
