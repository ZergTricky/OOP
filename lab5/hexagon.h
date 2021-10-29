#ifndef LAB5_HEXAGON_H
#define LAB5_HEXAGON_H


#include "iostream"
#include "point.h"

class Hexagon {
private:
    static const size_t size = 6;
    Point P[size];
public:
    Hexagon();

    double Area();

    size_t VertexesNumber();

    Hexagon &operator=(const Hexagon &other);

    friend bool operator==(const Hexagon &a, const Hexagon &b);

    friend std::istream &operator>>(std::istream &is, Hexagon &hexagon);

    friend std::ostream &operator<<(std::ostream &os, const Hexagon &hexagon);

    ~Hexagon();
};


#endif //LAB5_HEXAGON_H
