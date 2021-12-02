#include <iostream>
#include "bitstring.cpp"

int main() {
    BitString a(5, 10);
    BitString b(1, 0);
    std::cout << (a ^ b) << "\n";
    std::cout << (a & b) << "\n";
    BitString lit = 11001011010101111111010010101_bit;
    std::cout << lit << "\n";
    std::cout << (b ^ a ^ lit) << "\n";
    std::cout << (lit < a) << "\n";
    system("pause");// if you want to run exe
    return 0;
}
