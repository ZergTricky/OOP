#ifndef LAB5_TITERATOR_H
#define LAB5_TITERATOR_H

#include "iostream"
#include "memory"

using std::shared_ptr;

template<typename node, typename T>
class TIterator {
public:
    TIterator(shared_ptr<node> other) {
        ptr = other;
    }

    shared_ptr<T> operator*() {
        return ptr->GetVal();
    }

    shared_ptr<T> operator->() {
        return ptr->GetVal();
    }

    TIterator<node, T> operator++() {
        return ptr = ptr->GetNext();
    }

    TIterator<node, T> operator++(int) {
        TIterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator==(TIterator<node, T> const &other) {
        return ptr == other.ptr;
    }

    bool operator!=(TIterator<node, T> const &other) {
        return !(*this == other);
    }

private:
    shared_ptr<node> ptr;
};

#endif //LAB5_TITERATOR_H
