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

	if (cin.fail()|| kinder_anzahl <= 0) {
		cout << "Geben Sie mindestens 1 Kind ein." << endl;
		return -1;
	}

	kindergeld = (kinder_anzahl == 1)
		? ERSTES_KIND_GELD
		: ERSTES_KIND_GELD + ZWEITES_KIND_GELD + (kinder_anzahl - 2) * DRITTES_KIND_GELD;


	/*if (kinder_anzahl <= 0 || cin.fail())
	{
		cout << "Geben Sie mindestens 1 Kind ein." << endl;
		return 1;
	}
	else if (kinder_anzahl == 1)
	{
		kindergeld = ERSTES_KIND_GELD;
	}
	else 
	{
		kindergeld = ERSTES_KIND_GELD + ZWEITES_KIND_GELD + (kinder_anzahl - 2) * DRITTES_KIND_GELD;
	}*/


	cout << "Für " << kinder_anzahl << " erhalten Sie " << kindergeld << " Euro Kindergeld." << endl;
}