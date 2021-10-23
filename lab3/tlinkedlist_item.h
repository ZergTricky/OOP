#ifndef LAB3_TLINKEDLIST_ITEM_H
#define LAB3_TLINKEDLIST_ITEM_H

#include "hexagon.h"
#include "iostream"
#include "memory"

using std::shared_ptr;
using std::make_shared;

class TLinkedListItem {
private:
    shared_ptr<Hexagon> val;
    shared_ptr<TLinkedListItem> next;
public:
    TLinkedListItem(shared_ptr<Hexagon> hexagon, shared_ptr<TLinkedListItem> nxt);

    void SetNext(shared_ptr<TLinkedListItem> nxt);

    shared_ptr<TLinkedListItem> GetNext();

    shared_ptr<Hexagon> GetVal();

    friend std::ostream &operator<<(std::ostream &os, const TLinkedListItem &item);

    virtual ~TLinkedListItem();
};


#endif //LAB3_TLINKEDLIST_ITEM_H
