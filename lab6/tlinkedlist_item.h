#ifndef LAB6_TLINKEDLIST_ITEM_H
#define LAB6_TLINKEDLIST_ITEM_H

#include "hexagon.h"
#include "iostream"
#include "memory"

using std::shared_ptr;
using std::make_shared;

template <typename T>
class TLinkedListItem {
private:
    shared_ptr<T> val;
    shared_ptr<TLinkedListItem<T>> next;
public:
    TLinkedListItem(shared_ptr<T> hexagon, shared_ptr<TLinkedListItem<T>> nxt);

    void SetNext(shared_ptr<TLinkedListItem<T>> nxt);

    shared_ptr<TLinkedListItem<T>> GetNext();

    shared_ptr<T> GetVal();

    template<typename X>
    friend std::ostream &operator<<(std::ostream &os, const TLinkedListItem<X> &item);

    virtual ~TLinkedListItem();
};


#endif //LAB6_TLINKEDLIST_ITEM_H
