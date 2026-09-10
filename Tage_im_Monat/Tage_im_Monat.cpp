#include <iostream>
using namespace std;

#define CLEAR_CIN cin.clear(); cin.ignore(1000, '\n')

int main()
{
    int monat = 0;
    int tage = 0;
    bool invalidInput = true;

    // Eingabe und Fehlerabfrage
    while(invalidInput)
    {
        invalidInput = false;

        cout << "Bitte geben Sie den Monat ein (1-12):" << endl;
        cin >> monat;

        // Fehlerabfrage
        if (cin.fail() || monat < 1 || monat > 12) 
        {
            if (cin.fail()) // Keine Zahl eingegeben
            {
                cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;
            }
            else // Zahl nicht im angegebenen Bereich
            {
                cout << "Ungültige Eingabe. Bitte gebe eine Zahl zwischen 1-12 ein." << endl;
            }

            CLEAR_CIN;
            invalidInput = true;
        }
    }

    // Auswahl der Tage für den jeweiligen Monat
    switch (monat)
    {
        case 1:
        case 3: 
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: tage = 31;
                 break;
        case 2: tage = 28;
                break;
        case 4:
        case 6:
        case 9:
        case 11: tage = 30;
                 break;
        default: cout << "Fehlerhafte Eingabe";
    }

    // Ausgabe 
    cout << "Der " << monat << ".Monat hat " << tage << " Tage." << endl;
}