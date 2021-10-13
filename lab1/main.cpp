#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"

int main() {
    std::cout << "Enter a triangle: \n";
    Triangle T1(std::cin);
    std::cout << "Vertexes of triangle: " << T1.VertexesNumber() << "\n";
    T1.Print(std::cout);
    std::cout << "Area of triangle: " << T1.Area() << "\n";
    std::cout << "Enter a hexagon: \n";
    Hexagon H1(std::cin);
    std::cout << "Vertexes of hexagon: " << H1.VertexesNumber() << "\n";
    H1.Print(std::cout);
    std::cout << "Area of hexagon: " << H1.Area() << "\n";
    std::cout << "Enter a octagon: \n";
    Octagon O1(std::cin);
    std::cout << "Vertexes of octagon: " << O1.VertexesNumber() << "\n";
    O1.Print(std::cout);
    std::cout << "Area of octagon: " << O1.Area() << "\n";
    return 0;
}