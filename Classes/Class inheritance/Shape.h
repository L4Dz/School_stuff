#ifndef SHAPE_H
#define SHAPE_H

struct point {
    double x, y;
};

class Shape {
    point center_;

public:
    explicit Shape(const point &center);

    virtual ~Shape();

    const point &get_center() const;

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual bool contains(const point &p) const = 0;
};

#endif


