#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "de_DE.utf8");

	int kinder_anzahl = 0, kindergeld = 0;
	int const ERSTES_KIND_GELD = 350;
	int const ZWEITES_KIND_GELD = 250;
	int const DRITTES_KIND_GELD = 200;

	cout << "Geben Sie bitte die Anzahl der Kinder ein: ";
	cin >> kinder_anzahl;

	cerr << "\aFehler bei der Eingabe\nBitte korrigieren: ";
	cin >> kinder_anzahl;

	kindergeld = ERSTES_KIND_GELD + ZWEITES_KIND_GELD + (kinder_anzahl - 2) * DRITTES_KIND_GELD;

	cout << "Für " << kinder_anzahl << " erhalten Sie " << kindergeld << " Euro Kindergeld." << endl;
}