#include "tlinkedlist_item.h"

template<typename T>
TLinkedListItem<T>::~TLinkedListItem() {
    printf("DELETED ITEM\n");
}

template<typename T>
TLinkedListItem<T>::TLinkedListItem(shared_ptr<T> figure, shared_ptr<TLinkedListItem<T>> nxt) {
    val = figure;
    next = nxt;
}

template<typename T>
shared_ptr<TLinkedListItem<T>> TLinkedListItem<T>::GetNext() {
    return next;
}

template<typename T>
void TLinkedListItem<T>::SetNext(shared_ptr<TLinkedListItem<T>> nxt) {
    next = nxt;
}

template<typename T>
shared_ptr<T> TLinkedListItem<T>::GetVal() {
    return val;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const TLinkedListItem<T> &item) {
    os << *item.val;
    return os;
}

template class TLinkedListItem<Hexagon>;
template std::ostream &operator<<(std::ostream &os, const TLinkedListItem<Hexagon> &item) ;