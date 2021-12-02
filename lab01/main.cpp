#include "bitstring.h"

int main() {
    BitString a(0, 100);
    BitString b(1, 0);
    print(a);
    print(b);
    print(XOR(a, b));
    print(AND(a, b));
    a = ShiftLeft(a, 10);
    b = ShiftRight(b, 32);
    print(a);
    print(b);
    BitString c = OR(a, b);
    print(c);
    std::cout << (compare(a, b)) << "\n";

    a = BitString(5, 2);
    b = BitString(1, 2);
    std::cout << subMask(a, b) << "\n";

    a = OR(a, NOT(a));
    print(a);

    std::cout << a.count() << "\n";
    system("pause");// if you want to run exe
    return 0;
}
