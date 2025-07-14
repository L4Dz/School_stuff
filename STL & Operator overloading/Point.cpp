//
// Created by ladie on 07/07/2025.
//
#include "Point.h"

Point::Point() : x_(0), y_(0) {}

Point::Point(int x, int y) : x_(x), y_(y) {}

Point::Point(const Point &p) : x_(p.x_), y_(p.y_) {}

int Point::get_x() const {
    return x_;
}
int Point::get_y() const {
    return y_;
}
Point Point::operator+(const Point &p) const {
    return Point(x_ + p.x_, y_ + p.y_);
}

Point Point::operator*(int x) const {
    return Point(x_ * x, y_ * x);
}

Point& Point::operator+=(const Point &p) {
    x_ += p.x_;
    y_ += p.y_;
    return *this;
}
Point& Point::operator=(const Point &p) {
    x_ = p.x_;
    y_ = p.y_;
    return *this;
}

Point operator*(int x, const Point& p) {
    return Point(p.get_x()* x, p.get_y() * x);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.get_x() << "," << p.get_y() << ")";
    return os;
}



