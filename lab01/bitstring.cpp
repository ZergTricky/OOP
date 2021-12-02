#include "bitstring.h"

BitString::BitString() : first(0), second(0) {}

BitString::BitString(unsigned long long first, unsigned long long second) : first(first), second(second) {}

int BitString::count() const {
    return __builtin_popcountll(first) + __builtin_popcountll(second);
}

BitString AND(const BitString &a, const BitString &b) {
    return BitString(a.first & b.first, a.second & b.second);
}

BitString OR(const BitString &a, const BitString &b) {
    return BitString(a.first | b.first, a.second | b.second);
}

BitString XOR(const BitString &a, const BitString &b) {
    return BitString(a.first ^ b.first, a.second ^ b.second);
}

BitString NOT(const BitString &a) {
    return BitString(~a.first, ~a.second);
}

BitString ShiftLeft(const BitString &a, unsigned int cnt) {
    return BitString((a.first << cnt) + (a.second >> (64 - cnt)), a.second << cnt);
}

BitString ShiftRight(const BitString &a, unsigned int cnt) {
    return BitString(a.first >> cnt, (a.second >> cnt) + (a.first << (64 - cnt)));
}

bool operator==(const BitString &a, const BitString &b) {
    return a.first == b.first && a.second == b.second;
}

bool subMask(const BitString &a, const BitString &b) {
    return OR(a, b) == a;
}

bool compare(const BitString &a, const BitString &b) {
    return a.count() < b.count();
}

void print(const BitString &a) {
    for (int i = 63; i >= 0; --i) {
        if ((a.first >> i) & 1) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }
    for (int i = 63; i >= 0; --i) {
        if ((a.second >> i) & 1) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }
    std::cout << "\n";
}
