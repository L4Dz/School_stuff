#ifndef __Solid_h__
#define __Solid_h__

#include <iostream>

struct point {
    double x, y, z;
};

std::ostream &operator<<(std::ostream &os, const point &p);

class Solid {
    point center_;

public:
    Solid(const point &c);

    virtual ~Solid();

    const point &center() const;

    virtual double area() const = 0;
};

#endif
