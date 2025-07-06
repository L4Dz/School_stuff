#ifndef CYLINDER_H
#define CYLINDER_H

#include "Solid.h"
#include <cmath> // for M_PI

class Cylinder : public Solid {
public:
    Cylinder(const point& center, double radius, double height);

    double radius() const;
    double height() const;
    double area() const override;

private:
    double radius_;
    double height_;
};

#endif // CYLINDER_H
