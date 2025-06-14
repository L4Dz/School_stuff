//
// Created by ladie on 13/06/2025.
//
#include <cmath>
#include <math.h>

#include "Point2d.h"

void Point2d::translate(const Point2d& t) {
    x+=t.x;
    y+=t.y;
}

double Point2d::distance_to(const Point2d& p) const {

    return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));

}