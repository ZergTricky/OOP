#include "tlinkedlist.h"

int main() {
    Hexagon *hex[4];

    for (int i = 0; i < 4; ++i) {
        std::cout << "Enter a Hexagon: ";
        Hexagon hexagon;
        std::cin >> hexagon;
        hex[i] = new Hexagon(hexagon);
    }
    std::cout << "created!\n";

    for (int i = 0; i < 4; ++i) {
        std::cout << *hex[i] << "\n";
    }

    for (int i = 0; i < 4; ++i) {
        delete hex[i];
    }
    return 0;
}