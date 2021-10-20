#include "tlinkedlist_item.h"


TLinkedListItem::~TLinkedListItem() {
    printf("DELETED ITEM\n");
}

TLinkedListItem::TLinkedListItem(const Hexagon &hexagon, TLinkedListItem *nxt) {
    val = hexagon;
    next = nxt;
}

TLinkedListItem *TLinkedListItem::GetNext() {
    return next;
}

void TLinkedListItem::SetNext(TLinkedListItem *nxt) {
    next = nxt;
}

const Hexagon &TLinkedListItem::GetVal() {
    return val;
}

std::ostream &operator<<(std::ostream &os, const TLinkedListItem &item) {
    os << item.val;
    return os;
}
