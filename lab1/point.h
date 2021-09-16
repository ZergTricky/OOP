#ifndef LAB1_POINT_H
#define LAB1_POINT_H

#include <iostream>

class Point {
private:
    double _x, _y;
public:
    Point();

    Point(double x, double y);

    friend double operator*(Point &a, Point &b);

    friend Point operator-(Point &a, Point &b);

    friend double dist(Point &a, Point &b);

    friend std::istream &operator>>(std::istream &is, Point &p);

    friend std::ostream &operator<<(std::ostream &os, Point &p);
};


#endif //LAB1_POINT_H
