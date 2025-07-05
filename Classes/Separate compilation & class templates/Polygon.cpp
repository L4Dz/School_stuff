#include "Polygon.h"
#include <iostream>
#include <stdexcept>

Polygon::Polygon() = default;

Polygon::Polygon(const std::vector<Point>& points) : vertices(points) {}

void Polygon::add_vertex(int position, const Point& p) {
    if (position < 1 || position > static_cast<int>(vertices.size()) + 1) {
        throw std::out_of_range("Invalid vertex position");
    }
    vertices.insert(vertices.begin() + (position - 1), p);
}

Point Polygon::get_vertex(int position) const {
    if (position < 1 || position > static_cast<int>(vertices.size())) {
        throw std::out_of_range("Invalid vertex position");
    }
    return vertices[position - 1];
}

bool Polygon::get_vertex(int position, Point& p) const {
    if (position < 1 || position > static_cast<int>(vertices.size())) {
        return false;
    }
    p = vertices[position - 1];
    return true;
}

double Polygon::perimeter() const {
    double peri = 0.0;
    int n = vertices.size();
    if (n < 2) return 0.0;

    for (int i = 0; i < n; ++i) {
        peri += vertices[i].distance_to(vertices[(i + 1) % n]);
    }

    return peri;
}

void Polygon::show() const {
    std::cout << "{";
    for (const Point& p : vertices) {
        p.show();
    }
    std::cout << "}";
}

int Polygon::size() const {
    return vertices.size();
}
