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
    head = make_shared<TLinkedListItem>(list.head->GetVal(), nullptr);
    shared_ptr<TLinkedListItem> cur = head;
    shared_ptr<TLinkedListItem> it = list.head;
    for (size_t i = 0; i < len - 1; ++i) {
        it = it->GetNext();
        shared_ptr<TLinkedListItem> new_item = make_shared<TLinkedListItem>(it->GetVal(), nullptr);
        cur->SetNext(new_item);
        cur = cur->GetNext();
    }
}


shared_ptr<Hexagon> TLinkedList::First() {
    if (!len)return nullptr;
    return head->GetVal();
}

shared_ptr<Hexagon> TLinkedList::Last() {
    if (!len)return nullptr;
    shared_ptr<TLinkedListItem> cur = head;
    for (size_t i = 0; i < len - 1; ++i) {
        cur = cur->GetNext();
    }
    return cur->GetVal();
}

void TLinkedList::InsertFirst(shared_ptr<Hexagon> hexagon) {
    shared_ptr<TLinkedListItem> it = make_shared<TLinkedListItem>(hexagon, head);
    head = it;
    len++;
}

void TLinkedList::InsertLast(shared_ptr<Hexagon> hexagon) {
    if (!len) {
        head = make_shared<TLinkedListItem>(hexagon, nullptr);
        len++;
        return;
    }
    shared_ptr<TLinkedListItem> cur = head;
    for (size_t i = 0; i < len - 1; ++i) {
        cur = cur->GetNext();
    }
    shared_ptr<TLinkedListItem> it = make_shared<TLinkedListItem>(hexagon, nullptr);
    cur->SetNext(it);
    len++;
}

void TLinkedList::Insert(shared_ptr<Hexagon> hexagon, size_t pos) {
    if (pos < 0 || pos > len)return;
    shared_ptr<TLinkedListItem> cur = head;
    shared_ptr<TLinkedListItem> prev = nullptr;
    for (size_t i = 0; i < pos; ++i) {
        prev = cur;
        cur = cur->GetNext();
    }
    shared_ptr<TLinkedListItem> it = make_shared<TLinkedListItem>(hexagon, cur);
    if (prev) {
        prev->SetNext(it);
    } else {
        head = it;
    }
    len++;
}

void TLinkedList::RemoveFirst() {
    if (!len)return;
    shared_ptr<TLinkedListItem> del = head;
    head = head->GetNext();
    len--;
}

void TLinkedList::RemoveLast() {
    if (!len)return;
    if (len == 1) {
        head = nullptr;
        len = 0;
        return;
    }
    shared_ptr<TLinkedListItem> cur = head;
    for (size_t i = 0; i < len - 2; ++i) {
        cur = cur->GetNext();
    }
    shared_ptr<TLinkedListItem> del = cur->GetNext();
    cur->SetNext(nullptr);
    len--;
}

void TLinkedList::Remove(size_t pos) {
    if (!len)return;
    if (pos < 0 || pos >= len)return;
    shared_ptr<TLinkedListItem> cur = head;
    shared_ptr<TLinkedListItem> prev = nullptr;
    for (size_t i = 0; i < pos; ++i) {
        prev = cur;
        cur = cur->GetNext();
    }
    if (prev) {
        prev->SetNext(cur->GetNext());
    } else {
        head = cur->GetNext();
    }
    len--;
}

shared_ptr<Hexagon> TLinkedList::GetItem(size_t ind) {
    if (ind < 0 || ind >= len)return nullptr;
    shared_ptr<TLinkedListItem> cur = head;
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
    shared_ptr<TLinkedListItem> cur = list.head;
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