#include "bitstring.h"
#include "cstring"

BitString::BitString() : first(0), second(0) {}

BitString::BitString(unsigned long long first, unsigned long long second) : first(first), second(second) {}

int BitString::count() const {
    return __builtin_popcountll(first) + __builtin_popcountll(second);
}

BitString operator&(const BitString &a, const BitString &b) {
    return BitString(a.first & b.first, a.second & b.second);
}

BitString operator|(const BitString &a, const BitString &b) {
    return BitString(a.first | b.first, a.second | b.second);
}

BitString operator^(const BitString &a, const BitString &b) {
    return BitString(a.first ^ b.first, a.second ^ b.second);
}

BitString operator~(const BitString &a) {
    return BitString(~a.first, ~a.second);
}

BitString operator<<(const BitString &a, unsigned int cnt) {
    return BitString((a.first << cnt) + (a.second >> (64 - cnt)), a.second << cnt);
}

BitString operator>>(const BitString &a, unsigned int cnt) {
    return BitString(a.first >> cnt, (a.second >> cnt) + (a.first << (64 - cnt)));
}

bool operator==(const BitString &a, const BitString &b) {
    return a.first == b.first && a.second == b.second;
}

bool subMask(const BitString &a, const BitString &b) {
    return (a | b) == a;
}

bool operator<(const BitString &a, const BitString &b) {
    return a.count() < b.count();
}

std::istream &operator>>(std::istream &is, BitString &a) {
    is >> a.first >> a.second;
    return is;
}

std::ostream &operator<<(std::ostream &os, const BitString &a) {
    for (int i = 63; i >= 0; --i) {
        if ((a.first >> i) & 1) {
            os << "1";
        } else os << "0";
    }
    for (int i = 63; i >= 0; --i) {
        if ((a.second >> i) & 1) {
            os << "1";
        } else os << "0";
    }
    return os;
}

BitString operator "" _bit(const char *str) {
    unsigned long long first = 0, second = 0;
    int len = strlen(str);
    if (len <= 64) {
        for (int i = 0; i < len; ++i) {
            second *= 2;
            if (str[i] == '1')second++;
        }
    } else {
        for (int i = 0; i < len - 64; ++i) {
            first *= 2;
            if (str[i] == '1')first++;
        }
        for (int i = len - 64; i < len; ++i) {
            second *= 2;
            if (str[i] == '1')second++;
        }
    }
    return BitString(first, second);
}
