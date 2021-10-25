#include "tlinkedlist.h"

TLinkedList::TLinkedList() {
    len = 0;
    head = nullptr;
}

TLinkedList::TLinkedList(const TLinkedList &list) {
    len = list.len;
    if (!list.len) {
        head = nullptr;
        return;
    }
    head = new TLinkedListItem(list.head->GetVal(), nullptr);
    TLinkedListItem *cur = head;
    TLinkedListItem *it = list.head;
    for (size_t i = 0; i < len - 1; ++i) {
        it = it->GetNext();
        TLinkedListItem *new_item = new TLinkedListItem(it->GetVal(), nullptr);
        cur->SetNext(new_item);
        cur = cur->GetNext();
    }
}


const Hexagon &TLinkedList::First() {
    if (!len) {
        std::cout << "The list is empty!\n";
        return Hexagon();
    }
    return head->GetVal();
}

const Hexagon &TLinkedList::Last() {
    TLinkedListItem *cur = head;
    for (size_t i = 0; i < len - 1; ++i) {
        cur = cur->GetNext();
    }
    return cur->GetVal();
}

void TLinkedList::InsertFirst(const Hexagon &hexagon) {
    TLinkedListItem *it = new TLinkedListItem(hexagon, head);
    head = it;
    len++;
}

void TLinkedList::InsertLast(const Hexagon &hexagon) {
    if (!len) {
        head = new TLinkedListItem(hexagon, nullptr);
        len++;
        return;
    }
    TLinkedListItem *cur = head;
    for (size_t i = 0; i < len - 1; ++i) {
        cur = cur->GetNext();
    }
    TLinkedListItem *it = new TLinkedListItem(hexagon, nullptr);
    cur->SetNext(it);
    len++;
}

void TLinkedList::Insert(const Hexagon &hexagon, size_t pos) {
    if (pos > len || pos < 0)return;
    TLinkedListItem *cur = head;
    TLinkedListItem *prev = nullptr;
    for (size_t i = 0; i < pos; ++i) {
        prev = cur;
        cur = cur->GetNext();
    }
    TLinkedListItem *it = new TLinkedListItem(hexagon, cur);
    if (prev) {
        prev->SetNext(it);
    } else {
        head = it;
    }
    len++;
}

void TLinkedList::RemoveFirst() {
    if (!len)return;
    TLinkedListItem *del = head;
    head = head->GetNext();
    delete del;
    len--;
}

void TLinkedList::RemoveLast() {
    if (!len)return;
    if (len == 1) {
        head = nullptr;
        len = 0;
        return;
    }
    TLinkedListItem *cur = head;
    for (size_t i = 0; i < len - 2; ++i) {
        cur = cur->GetNext();
    }
    TLinkedListItem *del = cur->GetNext();
    cur->SetNext(nullptr);
    delete del;
    len--;
}

void TLinkedList::Remove(size_t pos) {
    if (!len)return;
    if (pos < 0 || pos >= len)return;
    TLinkedListItem *cur = head;
    TLinkedListItem *prev = nullptr;
    for (size_t i = 0; i < pos; ++i) {
        prev = cur;
        cur = cur->GetNext();
    }
    if (prev) {
        prev->SetNext(cur->GetNext());
    } else {
        head = cur->GetNext();
    }
    delete cur;
    len--;
}

const Hexagon &TLinkedList::GetItem(size_t ind) {
    if (ind < 0 || ind >= len) {
        std::cout << "NOT FOUND\n";
        return Hexagon();
    }
    TLinkedListItem *cur = head;
    for (size_t i = 0; i < ind; ++i) {
        cur = cur->GetNext();
    }
    return cur->GetVal();
}

bool TLinkedList::Empty() {
    return len == 0;
}

size_t TLinkedList::Length() {
    return len;
}

std::ostream &operator<<(std::ostream &os, const TLinkedList &list) {
    TLinkedListItem *cur = list.head;
    os << "List: \n";
    for (size_t i = 0; i < list.len; ++i) {
        os << *cur;
        cur = cur->GetNext();
    }
    return os;
}

void TLinkedList::Clear() {
    while (!(this->Empty())) {
        this->RemoveFirst();
    }
}

TLinkedList::~TLinkedList() {
    while (!(this->Empty())) {
        this->RemoveFirst();
    }
    printf("DELETED LIST\n");
}