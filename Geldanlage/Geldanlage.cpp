#include <iostream>
#include <iomanip>
#include <string>

#define CLEAR_CIN cin.clear(); cin.ignore(1000, '\n');

using namespace std;

// Eingabe einer Int Zahl
int getIntZahl(string text)
{
    setlocale(LC_ALL, "de_DE.utf8");

    int zahl = 0;
    bool invalid_input = true;

    while (invalid_input) {

        invalid_input = false;

        cout << "Bitte gib " + text + " ein: " << endl;
        cin >> zahl;

        if (cin.fail() || zahl <= 0) {
            cout << "Ungültige Eingabe. Geben Sie einen positiven Wert ein" << endl;
            CLEAR_CIN
            invalid_input = true;
        }
    }

    return zahl;
}

// Berechnung des neuen Anlagebetrags
double berechnung(double anlagebetrag, double zinssatz)
{
    double neuer_anlagebetrag = anlagebetrag * (1.0 + zinssatz);
    return neuer_anlagebetrag;
}

// Ausgabe des Anlagebtrags nach x Jahren
void ausgabe(int jahr, double anlagebetrag)
{
    cout << fixed << setprecision(2);
    cout << "Wert nach " << jahr << " Jahren: " << anlagebetrag << endl;
}


int main() {
    double anlagebetrag = getIntZahl("den Anlagebetrag");
    double zinssatz = (double)getIntZahl("den Zinssatz in %")/100;
    int laufzeit = getIntZahl("die Laufzeit in Jahren");
    for (int jahr = 1; jahr <= laufzeit; jahr++)
    {
        anlagebetrag = berechnung(anlagebetrag, zinssatz);
        ausgabe(jahr, anlagebetrag);
    }
}