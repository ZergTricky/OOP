#include "tlinkedlist.h"

int main() {
    shared_ptr<Hexagon> hex = make_shared<Hexagon>();
    std::cin >> *hex;
    shared_ptr<Hexagon> hex2 = make_shared<Hexagon>();
    std::cin >> *hex2;
    shared_ptr<Hexagon> hex1 = make_shared<Hexagon>();
    std::cin >> *hex1;
    TLinkedList<Hexagon> list;
    list.InsertFirst(hex1);
    list.InsertFirst(hex);
    list.InsertFirst(hex2);
    for (auto i : list) {
        std::cout << *i;
    }
    return 0;
}