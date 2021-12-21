#ifndef LAB6_POINT_H
#define LAB6_POINT_H

#include <iostream>

class Point {
private:
    double _x, _y;
public:
    Point();

    Point(double x, double y);

    friend bool operator==(const Point &a, const Point &b);

    friend double operator*(const Point &a, const Point &b);

    friend const Point operator-(const Point &a, const Point &b);

    friend double dist(const Point &a, const Point &b);

    friend std::istream &operator>>(std::istream &is, Point &p);

    friend std::ostream &operator<<(std::ostream &os, const Point &p);
};


#endif //LAB6_POINT_H
