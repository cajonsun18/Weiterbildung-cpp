#include <iostream>
#include "person.h"

int main()
{
    Person p1;
    Person p2;

    cout << ((p1.setNachname("Wacker")) ? "Nachname vergeben" : "Falsche Eingabe beim Nachnamen") << endl;
    cout << ((p1.setVorname("Willi")) ? "Vorname vergeben" : "Falsche Eingabe beim Vornamen") << endl;
    cout << ((p1.setStrasse("Alsterweg 100")) ? "Strasse vergeben" : "Falsche Eingabe bei der Strasse") << endl;
    cout << ((p1.setPlz("21234")) ? "Plz vergeben" : "Falsche Eingabe bei der Plz") << endl;
    cout << ((p1.setOrt("Hamburg")) ? "Ort vergeben" : "Falsche Eingabe beim Ort") << endl;

    p2 = p1;

    cout << p1.toString();

    cout << p2.toString();
}