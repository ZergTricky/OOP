#include "tvector.h"

template<typename T>
TVector<T>::TVector() {
    capacity = 1;
    size = 0;
    ptr = (TVectorItem<T> *) (malloc(sizeof(TVectorItem<T>) * capacity));
}

template<typename T>
TVector<T>::TVector(size_t size) : size(size) {
    capacity = size;
    ptr = (TVectorItem<T> *) (malloc(sizeof(TVectorItem<T>) * capacity));
}

template<typename T>
TVector<T>::TVector(size_t size, T filler) : size(size) {
    capacity = size;
    ptr = (TVectorItem<T> *) (malloc(sizeof(TVectorItem<T>) * capacity));
    for (size_t i = 0; i < capacity; ++i) {
        new(ptr + i) TVectorItem<T>(filler);
    }
}

template<typename T>
TVector<T>::TVector(const TVector &other) {
    size = other.size;
    capacity = other.capacity;
    ptr = (TVectorItem<T> *) (malloc(sizeof(TVectorItem<T>) * capacity));
    for (size_t i = 0; i < size; ++i) {
        ptr[i] = other.ptr[i];
    }
}

template<typename T>
void TVector<T>::InsertLast(const T &elem) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    new(ptr + size) TVectorItem<T>(elem);
    ++size;
}

template<typename T>
void TVector<T>::RemoveLast() {
    if (size == 0) {
        std::cout << "The length is zero!\n";
        return;
    }
    --size;
}

template<typename T>
const T &TVector<T>::Last() {
    return ptr[(size - 1)].GetValue();
}

template<typename T>
T &TVector<T>::operator[](const size_t &idx) {
    return ptr[idx].GetValue();
}

template<typename T>
bool TVector<T>::Empty() {
    return size == 0;
}

template<typename T>
size_t TVector<T>::Length() {
    return size;
}

template<typename T>
void TVector<T>::Clear() {
    size = 0;
}

template<typename T>
TVector<T>::~TVector<T>() {
    free(ptr);
}

template<typename T>
void TVector<T>::resize(const size_t &new_capacity) {
    capacity = new_capacity;
    ptr = (TVectorItem<T> *) realloc(ptr, capacity * sizeof(TVectorItem<T>));
}

template
class TVector<void *>;