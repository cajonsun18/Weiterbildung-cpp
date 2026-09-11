#include <iostream>
#include <iomanip>
#include <string>

#define CLEAR_CIN cin.clear(); cin.ignore(1000, '\n');

using namespace std;

// Eingabe einer Double Zahl
double getDoubleZahl()
{
    setlocale(LC_ALL, "de_DE.utf8");

    double zahl = 0.0;
    bool invalid_input = true;

    while (invalid_input) {

        invalid_input = false;

        cout << "Bitte gib Sie ihr Bruttogehalt pro Monat ein: " << endl;
        cin >> zahl;

        if (cin.fail() || zahl <= 0) {
            cout << "Ungültige Eingabe. Geben Sie einen positiven Wert größer 0 ein" << endl;
            CLEAR_CIN
            invalid_input = true;
        }
    }

    return zahl;
}

double berechnungSozialabgabe(double geld, double prozent)
{
    return geld * (prozent / 100);
}

// Ausgabe
void ausgabe(double zahl, string text)
{
    cout << fixed << setprecision(2);
    string angabe = text + " beträgt:";
    cout << left << setw(50) << angabe << right << setw(10) << zahl << " Euro" << endl;
}

double berechnungNettogehalt(double bruttogehalt)
{
    double krankenver = berechnungSozialabgabe(bruttogehalt, (14.6/2));
    ausgabe(krankenver, "Der Krankenversicherungsbeitrag");
    double rentenver = berechnungSozialabgabe(bruttogehalt, (18.6/2));
    ausgabe(rentenver, "Der Rentenversicherungsbeitrag");
    double pflegever = berechnungSozialabgabe(krankenver, (3.05/2));
    ausgabe(pflegever, "Der Pflegeversicherungsbeitrag");
    double arbeitslosenver = berechnungSozialabgabe(bruttogehalt, (2.4/2));
    ausgabe(arbeitslosenver, "Der Arbeitslosenversicherungsbeitrag");

    double steuern = berechnungSozialabgabe(bruttogehalt, 15);
    ausgabe(steuern, "Die Steuer");

    double nettogehalt = bruttogehalt - krankenver - rentenver - pflegever
        - arbeitslosenver - steuern;

    return nettogehalt;
}


int main() {
    double bruttogehalt = getDoubleZahl();
    double nettogehalt = berechnungNettogehalt(bruttogehalt);
    ausgabe(nettogehalt, "Das Nettogehalt");
}