#include "hexagon.h"

Hexagon::Hexagon() {}

Hexagon::Hexagon(std::istream &is) {
    for (size_t i = 0; i < size; ++i) {
        is >> P[i];
    }
}

double Hexagon::Area() {
    const double eps = 1e-9;
    bool convex = true;
    for (size_t i = 0; i < size - 1; ++i) {
        Point a = P[(i + 1) % size] - P[i];
        Point b = P[(i + 2) % size] - P[(i + 1) % size];
        if (a * b > eps) {
            convex = false;
        }
    }
    if (!convex) {
        return -1.0;
    }
    double area = 0.0;
    for (size_t i = 0; i < size; ++i) {
        area += dist(P[i], P[(i + 1) % size]);
    }
    if (area < 0.0)area = -1.0 * area;
    return area;
}

size_t Hexagon::VertexesNumber() {
    return size;
}

void Hexagon::Print(std::ostream &os) {
    os << "Hexagon: ";
    for (size_t i = 0; i < size; ++i) {
        os << P[i] << " ";
    }
    os << "\n";
}
