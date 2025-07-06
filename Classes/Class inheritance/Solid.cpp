#include "Solid.h"

#include <iomanip>

using std::ostream;

ostream &operator<<(ostream &os, const point &p) {
    return os << std::fixed << std::setprecision(3)
           << '(' << p.x << ',' << p.y << ',' << p.z << ')';
}

Solid::Solid(const point &c) : center_(c) {
}

Solid::~Solid() = default;

const point &Solid::center() const { return center_; }
//
// Created by ladie on 05/07/2025.
//
