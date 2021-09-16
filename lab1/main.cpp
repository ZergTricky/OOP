#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"

int main() {
    Octagon O(std::cin);
    O.Print(std::cout);
    std::cout << O.Area() << "\n";
    return 0;
}