#include "tvector_item.h"

template<typename T>
TVectorItem<T>::TVectorItem() {
    value = nullptr;
}

template<typename T>
TVectorItem<T>::TVectorItem(const TVectorItem<T> &other) {
    value = other.value;
}

template<typename T>
TVectorItem<T>::TVectorItem(const T &item) {
    value = item;
}

template<typename T>
T &TVectorItem<T>::GetValue() {
    return value;
}

template<typename T>
TVectorItem<T> &TVectorItem<T>::operator=(const TVectorItem<T> &other) {
    value = other.value;
    return *this;
}

template<typename T>
TVectorItem<T>::~TVectorItem<T>() {}

template
class TVectorItem<void *>;