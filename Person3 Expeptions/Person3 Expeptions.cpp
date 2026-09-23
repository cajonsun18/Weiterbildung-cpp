#include <iostream>
#include "person.h"

int main()
{

    try
    {
        Person p1;
        Person p2;

        p1.setNachname("Wacker");
        p1.setVorname("Willi");
        p1.setStrasse("Alsterweg 100");
        p1.setPlz("212343");
        p1.setOrt("Hamburg");

        p2 = p1;

        cout << p1.toString();

        cout << p2.toString();
    }
    catch (exception e)
    {
        cout << "Fehler: " << e.what() << endl ;
    }
    catch (...)
    {
        cout << "Allgemeiner nicht lokalisierbarer Fehler" << endl;
    }

}