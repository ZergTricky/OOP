#include "point.h"

Point::Point() : _x(0.0), _y(0.0) {}

Point::Point(double x, double y) : _x(x), _y(y) {}

double operator*(const Point &a, const Point &b) {
    return a._x * b._y - b._x * a._y;
}

const Point &operator-(const Point &a, const Point &b) {
    Point c;
    c._x = b._x - a._x;
    c._y = b._y - a._y;
    return c;
}

double dist(const Point &a, const Point &b) {
    double dx = (b._x - a._x);
    double mid = (b._y + a._y) / 2.0;
    return dx * mid;
}

std::istream &operator>>(std::istream &is, Point &p) {
    is >> p._x >> p._y;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Point &p) {
    os << "(" << p._x << ", " << p._y << ") ";
    return os;
}

bool operator==(const Point &a, const Point &b) {
    return (a._x == b._x && a._y == b._y);
}