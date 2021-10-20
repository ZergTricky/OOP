#ifndef LAB2_TLINKEDLIST_ITEM_H
#define LAB2_TLINKEDLIST_ITEM_H

#include "hexagon.h"
#include "iostream"

class TLinkedListItem {
private:
    Hexagon val;
    TLinkedListItem *next;
public:
    TLinkedListItem(const Hexagon &hexagon, TLinkedListItem *nxt);

    void SetNext(TLinkedListItem *nxt);

    TLinkedListItem *GetNext();

    const Hexagon &GetVal();

    friend std::ostream &operator<<(std::ostream &os,const TLinkedListItem &item);

    virtual ~TLinkedListItem();
};


#endif //LAB2_TLINKEDLIST_ITEM_H
