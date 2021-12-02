#ifndef LAB01_BITSTRING_H
#define LAB01_BITSTRING_H

#include "iostream"


class BitString {
private:
    unsigned long long first;
    unsigned long long second;
public:
    BitString();

    BitString(unsigned long long first, unsigned long long second);

    int count() const;

    friend BitString AND(const BitString &a, const BitString &b);

    friend BitString OR(const BitString &a, const BitString &b);

    friend BitString XOR(const BitString &a, const BitString &b);

    friend BitString NOT(const BitString &a);

    friend BitString ShiftLeft(const BitString &a, unsigned int cnt);

    friend BitString ShiftRight(const BitString &a, unsigned int cnt);

    friend bool operator==(const BitString &a, const BitString &b);

    friend bool subMask(const BitString &mask, const BitString &submask);

    friend bool compare(const BitString &a, const BitString &b);

    friend void print(const BitString &a);

    ~BitString() = default;
};


#endif //LAB01_BITSTRING_H
