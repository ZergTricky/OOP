#ifndef LAB02_BITSTRING_H
#define LAB02_BITSTRING_H

#include "iostream"


class BitString {
private:
    unsigned long long first;
    unsigned long long second;
public:
    BitString();

    BitString(unsigned long long first, unsigned long long second);

    int count() const;

    friend BitString operator&(const BitString &a, const BitString &b);

    friend BitString operator|(const BitString &a, const BitString &b);

    friend BitString operator^(const BitString &a, const BitString &b);

    friend BitString operator~(const BitString &a);

    friend BitString operator<<(const BitString &a, unsigned int cnt);

    friend BitString operator>>(const BitString &a, unsigned int cnt);

    friend bool operator==(const BitString &a, const BitString &b);

    friend bool subMask(const BitString &mask, const BitString &submask);

    friend bool operator<(const BitString &a, const BitString &b);

    friend std::ostream &operator<<(std::ostream &os, const BitString &a);

    friend std::istream &operator>>(std::istream &is, BitString &a);

    ~BitString() = default;
};


#endif //LAB02_BITSTRING_H
