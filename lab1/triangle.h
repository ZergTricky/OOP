#ifndef LAB1_TRIANGLE_H
#define LAB1_TRIANGLE_H

#include "figure.h"
#include "point.h"

#include <iostream>

class Triangle : public Figure {
private:
    static const int size = 3;
    Point P[size];
public:
    Triangle();

    Triangle(std::istream &is);

    double Area() override;

    size_t VertexesNumber() override;

    void Print(std::ostream &os) override;

};


#endif //LAB1_TRIANGLE_H
