//
// Created by ladie on 06/07/2025.
//
#include "Rectangle.h"

Rectangle::Rectangle(const point& center, double width, double height)
    : Shape(center), width_(width), height_(height) {}

double Rectangle::area() const {
    return width_ * height_;
}

double Rectangle::perimeter() const {
    return 2 * (width_ + height_);
}

bool Rectangle::contains(const point& p) const {
    point c = get_center();
    return (p.x >= c.x - width_ / 2 && p.x <= c.x + width_ / 2 &&
            p.y >= c.y - height_ / 2 && p.y <= c.y + height_ / 2);
}
