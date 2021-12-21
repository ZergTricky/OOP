#ifndef LAB6_TVECTOR_H
#define LAB6_TVECTOR_H

#include <memory>
#include "iostream"
#include "tvector_item.h"
#include <new>

template<typename T>
class TVector {
public:
    TVector();

    TVector(size_t size);

    TVector(size_t size, T filler);

    TVector(const TVector &other);

    void InsertLast(const T &elem);

    void RemoveLast();

    const T &Last();

    T &operator[](const size_t& idx);

    void resize(const size_t &new_capacity);

    bool Empty();

    size_t Length();

    void Clear();

    ~TVector();

private:
    size_t capacity;
    size_t size;

    TVectorItem<T> *ptr;
};


#endif //LAB6_TVECTOR_H
