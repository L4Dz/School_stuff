#ifndef POINT_H
#define POINT_H

class Point {
private:
    int x, y;

public:
    Point();
    Point(int x, int y);

    int get_x() const;
    int get_y() const;
    void set_x(int x);
    void set_y(int y);

    double distance_to(const Point& p) const;
    void show() const;
};

#endif
