#include <iostream>
#include "person.h"

using namespace std;

void ausgabe(const Person& p);

int main()
{
    try
    {
        Person p1;
        Person p2("Banner", "Bruce");
        Person p3("Rogers", "Steve", "privat", "Brooklynweg", "12", "20095", "Hamburg", "24.09.2022");

        Person p4 = p3;
        Person p5(p3);

        p4.getAdresse()->setStrasse("Elbstrasse");
        p5.getAdresse()->setStrasse("Flussufer");

        ausgabe(p1);

        p1 = p4;// entspricht p1.operator=(p4);

        p1.getAdresse()->setStrasse("Sonderweg");

        ausgabe(p1);
        ausgabe(p4);

        cout << p2 << endl;
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

static void ausgabe(const Person& p)
{
    cout << p.toString();
}
