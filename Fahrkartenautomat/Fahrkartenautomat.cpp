#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "de_DE.utf8");

    int wahl = 0;
    double geldeinwurf = 0.0,
           fahrtkosten = 0.0,
           rueckgeld = 0.0;

    string ziel = " ";

    const double KOELN_FAHRTKOSTEN = 27.50;
    const double HAMBURG_FAHRTKOSTEN = 15.00;
    const double BERLIN_FAHRTKOSTEN = 65.00;
    const double MUENCHEN_FAHRTKOSTEN = 175.00;

    const string KOELN = "Köln";
    const string HAMBURG = "Hamburg";
    const string BERLIN = "Berlin";
    const string MUENCHEN = "München";

    cout << "Geben Sie einen Zielort ein (1-4): " << endl
        << left << "1.) " << setw(19) << KOELN << KOELN_FAHRTKOSTEN << " Euro" << endl
        << left << "2.) " << setw(20) << HAMBURG << HAMBURG_FAHRTKOSTEN << " Euro" << endl
        << left << "3.) " << setw(20) << BERLIN << BERLIN_FAHRTKOSTEN << " Euro" << endl
        << left << "4.) " << setw(20) << MUENCHEN << MUENCHEN_FAHRTKOSTEN << " Euro" << endl;
    cout << "Ihre Wahl: ";
	cin >> wahl;

    fahrtkosten = (wahl == 1) ? KOELN_FAHRTKOSTEN :
                  (wahl == 2) ? HAMBURG_FAHRTKOSTEN :
                  (wahl == 3) ? BERLIN_FAHRTKOSTEN :
                                MUENCHEN_FAHRTKOSTEN;

    ziel =  (wahl == 1) ? KOELN :
            (wahl == 2) ? HAMBURG :
            (wahl == 3) ? BERLIN :
                          MUENCHEN;

    cout << "Bitte zahlen Sie für ein Fahrt nach " << ziel << " " << fahrtkosten << " Euro" << endl;

    cout << "Einwurf an Geld: ";
    cin >> geldeinwurf;

    rueckgeld = geldeinwurf - fahrtkosten;

    cout << "Ihr Rückgeld: " << rueckgeld << " Euro" << endl
        << "Vielen Dank, bitte entnehmen Sie Ihre Fahrtkarte.";

}