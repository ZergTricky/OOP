#include "tlinkedlist.h"

using std::cin;
using std::cout;

int main() {
    TLinkedList list;
    cout << list.Length() << "\n";
    shared_ptr<Hexagon> hex = make_shared<Hexagon>();
    cin >> *hex;
    list.InsertFirst(hex);
    cin >> *hex;
    list.InsertFirst(hex);
    cin >> *hex;
    list.InsertFirst(hex);
    cin >> *hex;
    list.InsertFirst(hex);
    cout << list << "\n";
    size_t pos;
    cin >> pos;
    list.Remove(pos);
    cout << list << "\n";
    return 0;
}