#ifndef LAB1_HEXAGON_H
#define LAB1_HEXAGON_H

#include "figure.h"
#include "point.h"

class Hexagon : public Figure {
private:
    static const size_t size = 6;
    Point P[size];
public:
    Hexagon();

    Hexagon(std::istream &is);

    double Area() override;

    size_t VertexesNumber() override;

    void Print(std::ostream &os) override;
};


#endif //LAB1_HEXAGON_H
