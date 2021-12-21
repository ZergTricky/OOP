#include "hexagon.h"


Hexagon::Hexagon() {}

TAllocator Hexagon::alloc(sizeof(Hexagon), 10);

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

Hexagon &Hexagon::operator=(const Hexagon &other) {
    for (size_t i = 0; i < size; ++i) {
        this->P[i] = other.P[i];
    }
    return *this;
}

bool operator==(const Hexagon &a, const Hexagon &b) {
    for (size_t i = 0; i < Hexagon::size; ++i) {
        if (!(a.P[i] == b.P[i]))return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Hexagon &hexagon) {
    os << "Hexagon: ";
    for (size_t i = 0; i < Hexagon::size; ++i) {
        os << hexagon.P[i];
    }
    os << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, Hexagon &hexagon) {
    for (size_t i = 0; i < hexagon.size; ++i) {
        is >> hexagon.P[i];
    }
    return is;
}

void *Hexagon::operator new(size_t sz) {
    return alloc.allocate(sz);
}

void Hexagon::operator delete(void *ptr, size_t sz) noexcept {
    alloc.deallocate(ptr);
}

Hexagon::~Hexagon() {}