#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Person
{
    string nachname;
    string vorname;
    string strasse;
    string plz;
    string ort;
};

void ausgabe( Person person);

int main()
{
    struct Person peter;
    peter.nachname = "Meier";
    peter.vorname = "Peter";
    peter.strasse = "Lange Strasse";
    peter.plz = "46371";
    peter.ort = "Stuttgart";

    ausgabe(peter);
}

void ausgabe(Person person)
{
    cout << left << setw(12) << "Nachname: " << person.nachname << endl
         << left << setw(12) << "Vorname: " << person.vorname << endl
         << left << setw(12) << "Strasse: " << person.strasse << endl
         << left << setw(12) << "PLZ: " << person.plz << endl
         << left << setw(12) << "Ort: " << person.ort << endl;
}
