#include "Point.h"
#include <iostream>
#include <cmath>

Point::Point() : x(0), y(0) {}

Point::Point(int x_, int y_) : x(x_), y(y_) {}

int Point::get_x() const {
    return x;
}

int Point::get_y() const {
    return y;
}

void Point::set_x(int x_) {
    x = x_;
}

void Point::set_y(int y_) {
    y = y_;
}

double Point::distance_to(const Point& p) const {
    int dx = x - p.x;
    int dy = y - p.y;
    return std::sqrt(dx * dx + dy * dy);
}

void Point::show() const {
    std::cout << "(" << x << "," << y << ")";
}
