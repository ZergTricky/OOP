#ifndef LAB1_FIGURE_H
#define LAB1_FIGURE_H

#include <iostream>

class Figure {
public:
    virtual double Area() = 0;

    virtual size_t VertexesNumber() = 0;

    virtual void Print(std::ostream &os) = 0;
};


#endif //LAB1_FIGURE_H
