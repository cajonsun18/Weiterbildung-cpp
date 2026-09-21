#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool schaltjahr();
bool schaltjahr(int j);

int main()
{
    int jahr = 0;

    cout << "Gebe ein Jahr ein: " << endl;
    cin >> jahr;

    bool isSchaltjahr = schaltjahr(jahr);

    cout << "Das von dir eingegebene Jahr " << jahr << " ist "
        << ((isSchaltjahr) ? "ein" : "kein")
        << " Schaltjahr" << endl;

    isSchaltjahr = schaltjahr();

    cout << endl;
    cout << "Das jetztige Jahr ist "
        << ((isSchaltjahr) ? "ein" : "kein")
        << " Schaltjahr" << endl;
}



bool schaltjahr()
{
    // Systemdatum / zeit lesen     //(Vergangene Sekunden seit 01.01.1970) lesen
    const time_t now = (unsigned)time(NULL);

    //Strukturvariable für Datums- und Zeit anlegen
    struct tm zeit;

    //Datum/Zeit umwandeln und in Struktur legen
    localtime_s(&zeit, &now);

    //Auslesen der Struktur   
    int tag = zeit.tm_mday;
    int monat = zeit.tm_mon + 1;
    int jahr = zeit.tm_year + 1900;  //year liefert 126, die Struktur die Jahre, relat. zu 1900 angibt.

    return schaltjahr(jahr);
}

bool schaltjahr(int j)
{
    return j % 400 == 0 || j % 4 == 0 && j % 100 != 0;
}
