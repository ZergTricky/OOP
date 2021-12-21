#ifndef LAB6_HEXAGON_H
#define LAB6_HEXAGON_H

#include "iostream"
#include "point.h"
#include "tallocator.h"

class Hexagon {
private:
    static const size_t size = 6;
    static TAllocator alloc;
    Point P[size];
public:
    Hexagon();

    double Area();

    size_t VertexesNumber();

    Hexagon &operator=(const Hexagon &other);

    friend bool operator==(const Hexagon &a, const Hexagon &b);

    friend std::istream &operator>>(std::istream &is, Hexagon &hexagon);

    friend std::ostream &operator<<(std::ostream &os, const Hexagon &hexagon);

    void *operator new(size_t sz);

    void operator delete(void *ptr, size_t sz) noexcept;

    ~Hexagon();
};


#endif //LAB6_HEXAGON_H
