#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"
#include <vector>

class Polygon {
private:
    std::vector<Point> vertices;

public:
    Polygon();  // Default constructor
    Polygon(const std::vector<Point>& points);  // Constructor from vector

    void add_vertex(int position, const Point& p);
    Point get_vertex(int position) const;
    bool get_vertex(int position, Point& p) const;

    double perimeter() const;
    void show() const;
    int size() const;
};

#endif
