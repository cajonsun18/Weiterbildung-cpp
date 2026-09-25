#include "assistenzhund.h"
#include <iostream>

using namespace std;

int main()
{
    Hund h("Bello", "braun", 12);

    cout << h.gibLaut() << endl;
    cout << h.toString();

    Assistenzhund a1("Fixi", "weiss", 3, "Dackel", "Spuerhund");
    Assistenzhund a2("Maya", "gelb", 2, "Golden Retriever", "Blindenhund");

    cout << a1.toString();
    cout << a2.toString();
}
