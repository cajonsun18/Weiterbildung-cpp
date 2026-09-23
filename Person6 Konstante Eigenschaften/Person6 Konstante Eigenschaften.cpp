#include <iostream>
#include "person.h"

using namespace std;

void ausgabe(const string& titel, const Person& p);

int main()
{
    try
    {
        // 1.
        Person p1;
        ausgabe("p1 - Standardkonstruktor + Setter", p1);

        // 2.
        Person p2("Banner", "Bruce");
        ausgabe("p2 - Konstruktor mit Name", p2);

        // 3.
        Person p3("Rogers", "Steve", "Brooklynweg 12", "20095", "Hamburg", "24.09.2022");
        ausgabe("p3 - Konstruktor mit allen Daten", p3);

        // 4. Ungueltige Daten im Konstruktor
        cout << "Versuche Person mit ungueltiger PLZ zu erstellen..." << endl;
        Person p4("Parker", "Peter", "Queensweg 5", "123", "Berlin", "17.03.1976");
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

static void ausgabe(const string& titel, const Person& p)
{
    cout << titel << ":" << endl;
    cout << "   " << p.toString() << endl << endl;
}
