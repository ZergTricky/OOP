#include "triangle.h"

Triangle::Triangle() {}

Triangle::Triangle(std::istream &is) {
    for (size_t i = 0; i < size; ++i) {
        is >> P[i];
    }
}

double Triangle::Area() {
    double area = 0.0;
    for (size_t i = 0; i < size; ++i) {
        area += dist(P[i], P[(i + 1) % size]);
    }
    if (area < 0)area = -1.0 * area;
    return area;
}

size_t Triangle::VertexesNumber() {
    return size;
}

void Triangle::Print(std::ostream &os) {
    os << "Triangle: ";
    for (size_t i = 0; i < size; ++i) {
        os << P[i] << " ";
    }
    os << "\n";
}