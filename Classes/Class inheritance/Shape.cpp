//
// Created by ladie on 05/07/2025.
//
#include "Shape.h"

Shape::Shape(const point &center) : center_(center) { }

Shape::~Shape() = default;

const point &Shape::get_center() const { return center_; }
