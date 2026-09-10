#include <iostream>
#include <string>

#define CLEAR_CIN cin.clear(); cin.ignore(1000, '\n');

using namespace std;

int main()
{
    setlocale(LC_ALL, "de_DE.utf8");

    int datum = 0;
    int jahr = 0;
    int tage_insgesamt = 0;
    int tage_rest = 0;
    int tage_monat = 0;
    int extratag = 0;
    int i = 0;
    bool invalidInput = true;
    bool letzten_Monat_erreicht = false;
    string monat = " ";

    // Eingabe und Fehlerabfrage
    while (invalidInput)
    {
        invalidInput = false;

        cout << "Bitte geben Sie das Datum ein: " << endl;
        cin >> datum;

        // Fehlerabfrage
        if (cin.fail())
        {
            cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;
            CLEAR_CIN
            invalidInput = true;
        }
    }

    // Jahr bestimmen
    jahr = datum / 1000;
    
    tage_insgesamt = datum % 1000;

    // Bestimmen, ob es sich um ein Schaltjahr handelt
    if ((jahr % 400 == 0) || (jahr % 4 == 0 && jahr % 100 != 0)) {
        extratag = 1;
    }

    tage_rest = tage_insgesamt;

    // Monat (i) und Tag (tage_rest) bestimmen
    while (!letzten_Monat_erreicht)
    {
        i++;

        switch (i)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: tage_monat = 31;
                break;
            case 2: tage_monat = 28 + extratag;
                break;
            case 4:
            case 6:
            case 9:
            case 11: tage_monat = 30;
                break;
            default: cout << "Kein valider Monat";
        }

        if (tage_rest <= tage_monat) {
            letzten_Monat_erreicht = true;
        }
        else
        {
            tage_rest -= tage_monat;
        }
    }

    cout << "Das Datum ist: " 
         << ((tage_rest < 10) ? "0" : "") << tage_rest << "."
         << ((i < 10) ? "0" : "") << i << "."
         << jahr << endl;


    // Monat bestimmen
    switch (i)
    {
        case 1: monat = "Januar";
                break;
        case 2: monat = "Februar";
                break;
        case 3: monat = "März";
                break;
        case 4: monat = "April";
                break;
        case 5: monat = "Mai";
                break;
        case 6: monat = "Juni";
                break;
        case 7: monat = "Juli";
                break;
        case 8: monat = "August";
                break;
        case 9: monat = "September";
                break;
        case 10: monat = "Oktober";
                 break;
        case 11: monat = "November";
                 break;
        case 12: monat = "Dezember";
                 break;
        default: cout << "Kein valider Monat";
    }
    
    cout << "Das Datum ist: "
         << ((tage_rest < 10) ? "0" : "") << tage_rest << "."
         << monat << "."
         << jahr << endl;
}

