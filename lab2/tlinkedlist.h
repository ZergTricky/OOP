#ifndef LAB2_TLINKEDLIST_H
#define LAB2_TLINKEDLIST_H

#include "hexagon.h"
#include "tlinkedlist_item.h"
#include "iostream"

class TLinkedList {
private:
    size_t len;
    TLinkedListItem *head;
public:
    TLinkedList();

    TLinkedList(const TLinkedList &list);

    const Hexagon &First();

    const Hexagon &Last();

    void InsertFirst(const Hexagon &hexagon);

    void InsertLast(const Hexagon &hexagon);

    void Insert(const Hexagon &hexagon, size_t pos);

    void RemoveFirst();

    void RemoveLast();

    void Remove(size_t pos);

    const Hexagon &GetItem(size_t ind);

    bool Empty();

    size_t Length();

    friend std::ostream &operator<<(std::ostream &os, const TLinkedList &list);

    void Clear();

    virtual ~TLinkedList();
};


#endif //LAB2_TLINKEDLIST_H
