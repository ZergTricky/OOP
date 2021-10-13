#include "octagon.h"

Octagon::Octagon() {}

Octagon::Octagon(std::istream &is) {
    for (size_t i = 0; i < size; ++i) {
        is >> P[i];
    }
}

double Octagon::Area() {
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
    if (area < -eps)area = -1.0 * area;
    return area;
}

size_t Octagon::VertexesNumber() {
    return size;
}

void Octagon::Print(std::ostream &os) {
    os << "Octagon: ";
    for (size_t i = 0; i < size; ++i) {
        os << P[i] << " ";
    }
    os << "\n";
}
