#include "tlinkedlist.h"

using std::cin;
using std::cout;

int main() {
    TLinkedList<Hexagon> list;
    shared_ptr<Hexagon> hex1 = make_shared<Hexagon>();
    cin >> *hex1;
    list.InsertLast(hex1);
    cout << *(list.First()) << "\n";
    cout << *(list.Last()) << "\n";
    shared_ptr<Hexagon> hex2 = make_shared<Hexagon>();
    cin >> *hex2;
    list.InsertLast(hex2);
    cout << list << "\n";
    list.Insert(hex1, 2);
    cout << list << "\n";
    list.Remove(1);
    cout << list << "\n";
    return 0;
}