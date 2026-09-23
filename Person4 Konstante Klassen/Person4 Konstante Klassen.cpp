#include <iostream>
#include "person.h"

void ausgabe(const Person& p);

int main()
{

    try
    {
        Person p1;
        Person p2;

        p1.setNachname("Wacker");
        p1.setVorname("Willi");
        p1.setStrasse("Alsterweg 100");
        p1.setPlz("21234");
        p1.setOrt("Hamburg");

        p2 = p1;

        ausgabe(p1);
        ausgabe(p2);
    }
    catch (exception e)
    {
        cout << "Fehler: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Allgemeiner nicht lokalisierbarer Fehler" << endl;
    }

}

void ausgabe(const Person &p)
{
    cout << p.toString();
}
