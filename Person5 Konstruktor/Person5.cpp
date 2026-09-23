#include <iostream>
#include "person.h"

using namespace std;

static void ausgabe(const string& titel, const Person &p)
{
    cout << titel << ":" << endl;
    cout << "   " << p.toString() << endl << endl;
}

int main()
{
    try
    {
        // 1.
        Person p1;
        /*p1.setNachname("Stark");
        p1.setVorname("Tony");
        p1.setStrasse("Krasweg 24");
        p1.setPlz("21256");
        p1.setOrt("Hannover");*/
        ausgabe("p1 - Standardkonstruktor + Setter", p1);

        // 2.
        Person p2("Banner", "Bruce");
        ausgabe("p2 - Konstruktor mit Name", p2);

        // 3.
        Person p3("Rogers", "Steve", "Brooklynweg 12", "20095", "Hamburg");
        ausgabe("p3 - Konstruktor mit allen Daten", p3);

        // 4. Ungueltige Daten im Konstruktor
        cout << "Versuche Person mit ungueltiger PLZ zu erstellen..." << endl;
        Person p4("Parker", "Peter", "Queensweg 5", "123", "Berlin");
        ausgabe("p4", p4);
    }
    catch (const exception& ex)
    {
        cout << "Fehler: " << ex.what() << endl;
    }
    catch (...)
    {
        cout << "Fehler nicht lokalisierbar." << endl;
    }
}
