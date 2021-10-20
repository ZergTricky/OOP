#include "tlinkedlist.h"

using namespace std;

int main() {
    TLinkedList list;
    cout << list.Length() << "\n";
    Hexagon hex;
    cin >> hex;
    list.InsertFirst(hex);
    cout << list;
    cout << list.Length() << "\n";
    cin >> hex;
    list.InsertFirst(hex);
    cout << list;
    cout << list.Length() << "\n";
    list.RemoveLast();
    cout << list;
    cout << list.Length() << "\n";
    list.RemoveFirst();
    cout << list;
    cout << list.Length() << "\n";
    return 0;
}