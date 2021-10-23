#ifndef LAB3_TLINKEDLIST_H
#define LAB3_TLINKEDLIST_H

#include "tlinkedlist_item.h"

class TLinkedList {
private:
    size_t len;
    shared_ptr<TLinkedListItem> head;
public:
    TLinkedList();

    TLinkedList(const TLinkedList &list);

    shared_ptr<Hexagon> First();

    shared_ptr<Hexagon> Last();

    void InsertFirst(shared_ptr<Hexagon> hexagon);

    void InsertLast(shared_ptr<Hexagon> hexagon);

    void Insert(shared_ptr<Hexagon> hexagon, size_t pos);

    void RemoveFirst();

    void RemoveLast();

    void Remove(size_t pos);

    shared_ptr<Hexagon> GetItem(size_t ind);

    bool Empty();

    size_t Length();

    friend std::ostream &operator<<(std::ostream &os, const TLinkedList &list);

    void Clear();

    virtual ~TLinkedList();
};


#endif //LAB3_TLINKEDLIST_H
