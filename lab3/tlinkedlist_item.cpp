#include "tlinkedlist_item.h"


TLinkedListItem::~TLinkedListItem() {
    printf("DELETED ITEM\n");
}

TLinkedListItem::TLinkedListItem(shared_ptr<Hexagon> hexagon, shared_ptr<TLinkedListItem> nxt) {
    val = hexagon;
    next = nxt;
}

shared_ptr<TLinkedListItem> TLinkedListItem::GetNext() {
    return next;
}

void TLinkedListItem::SetNext(shared_ptr<TLinkedListItem> nxt) {
    next = nxt;
}

shared_ptr<Hexagon> TLinkedListItem::GetVal() {
    return val;
}

std::ostream &operator<<(std::ostream &os, const TLinkedListItem &item) {
    os << *item.val;
    return os;
}
