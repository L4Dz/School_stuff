//
// Created by ladie on 06/07/2025.
//

#define _USE_MATH_DEFINES
#include <cmath>
#include "Circle.h"

Circle::Circle(const point& center, double radius)
    : Shape(center), radius_(radius) {}

double Circle::area() const {
    return M_PI * radius_ * radius_;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius_;
}

bool Circle::contains(const point& p) const {
    point c = get_center();
    double dx = p.x - c.x;
    double dy = p.y - c.y;
    return dx * dx + dy * dy <= radius_ * radius_;
}
