#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct Adresse
{
    string adressart;
    string strasse;
    int plz;
    string ort;
};

struct Person
{
    string nachname;
    string vorname;
    vector<Adresse> adressen;
};

void ausgabe(Person person);

int main()
{
    struct Person peter;
    peter.nachname = "Meier";
    peter.vorname = "Peter";

    Adresse adr = { "privat", "Lange Strasse", 46371, "Stuttgart" };

    peter.adressen.push_back(adr);

    ausgabe(peter);

    peter.adressen.resize(3);
    peter.adressen[1].adressart = "oeffentlich";
    peter.adressen[1].strasse = "Musterstrasse";
    peter.adressen[1].plz = 87543;
    peter.adressen[1].ort = "Frankfurt";

    cout << endl;
    cout << "Es wurde eine weitere Adresse zu Peter hinzugefuegt: " << endl;

    ausgabe(peter);

}

void ausgabe(Person person)
{
    cout << left << setw(12) << "Nachname: " << person.nachname << endl
        << left << setw(12) << "Vorname: " << person.vorname << endl;

    for (int i = 0; i < person.adressen.size(); i++)
    {
        cout << endl;
        cout << i+1 << ".Adresse: " << endl
            << left << setw(12) << "Adressart: " << person.adressen[i].adressart << endl
            << left << setw(12) << "Strasse: " << person.adressen[i].strasse << endl
            << left << setw(12) << "PLZ: " << person.adressen[i].plz << endl
            << left << setw(12) << "Ort: " << person.adressen[i].ort << endl;
    }
    
}
