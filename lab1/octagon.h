#ifndef LAB1_OCTAGON_H
#define LAB1_OCTAGON_H

#include "figure.h"
#include "point.h"


class Octagon : public Figure {
private:
    static const size_t size = 8;
    Point P[size];
public:
    Octagon();

    Octagon(std::istream &is);

    double Area() override;

    size_t VertexesNumber() override;

    void Print(std::ostream &os) override;
};


#endif //LAB1_OCTAGON_H
