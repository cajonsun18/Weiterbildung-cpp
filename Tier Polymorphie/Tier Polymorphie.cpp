#include <iostream>
#include <vector>
#include "hund.h"
#include "schwein.h"
#include "auto.h"
#include "motorrad.h"

using namespace std;

int main()
{
    // ---------- Keine Polymorphie ---------------
    cout << "----- KEINE POLYMORPHIE -----" << endl;
    Motorrad m("EU917",2);
    cout << m.toString() << endl;

    Auto a("HI423", "ausklappbar");
    cout << a.toString() << endl;
    
    vector<Fahrzeug> vFahrzeug;
    vFahrzeug.push_back(m);
    vFahrzeug.push_back(a);

    for (auto element : vFahrzeug)
    {
        cout << element.toString() << endl;
    }

    // ---------- Polymorphie ---------------
    cout << "----- POLYMORPHIE -----" << endl;
    Hund h("Bello", 12, "Dackel");

    //cout << h.getLaut() << endl;
    cout << h.toString();

    Schwein s("Pinki", 3, "450");

    //cout << s.getLaut() << endl;
    cout << s.toString();

    vector<Tier*> vTier2;
    vTier2.push_back(&h);
    vTier2.push_back(&s);

    for (auto element: vTier2)
    {
        cout << element->toString() << endl;
    }
}