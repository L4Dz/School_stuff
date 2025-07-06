#define _USE_MATH_DEFINES
#include "Cylinder.h"

Cylinder::Cylinder(const point& center, double radius, double height)
    : Solid(center), radius_(radius), height_(height) { }

double Cylinder::radius() const {
    return radius_;
}

double Cylinder::height() const {
    return height_;
}

double Cylinder::area() const {
    return 2 * M_PI * radius_ * (radius_ + height_);
}
