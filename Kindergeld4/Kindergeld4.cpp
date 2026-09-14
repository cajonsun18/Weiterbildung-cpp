#include <iostream>
#include <string>

#define CLEAR_CIN cin.clear(); cin.ignore(1000, '\n');

using namespace std;

// Eingabe der Kinderanzahl über die Konsole
int hole_kinderzahl()
{
	int kinder_anzahl = 0;
	bool invalid_input = true;

	while (invalid_input) {

		invalid_input = false;

		cout << "Geben Sie bitte die Anzahl der Kinder ein: ";
		cin >> kinder_anzahl;

		if (cin.fail() || kinder_anzahl <= 0) {
			cout << "Geben Sie mindestens 1 Kind  ein." << endl;
			CLEAR_CIN
				invalid_input = true;
		}
	}

	return kinder_anzahl;
}

// Berechnung des Kindergeld in Abhängigkeit der Kinderanzahl
double berechne_kindergeld(int kinder_anzahl)
{
	int const ERSTES_KIND_GELD = 350;
	int const ZWEITES_KIND_GELD = 250;
	int const DRITTES_KIND_GELD = 200;

	double kindergeld = (kinder_anzahl == 1)
		? ERSTES_KIND_GELD
		: ERSTES_KIND_GELD + ZWEITES_KIND_GELD + (kinder_anzahl - 2) * DRITTES_KIND_GELD;

	return kindergeld;
}

// Ausgabe der Kinderanzahl und des berechneten Kindergeldes
void ausgabe(int kinder_anzahl, double kindergeld)
{
	setlocale(LC_ALL, "de_DE.utf8");
	cout << "Für " << kinder_anzahl << ((kinder_anzahl == 1) ? " Kind" : " Kinder")
		<< " erhalten Sie " << kindergeld << " Euro Kindergeld." << endl;
}


int main(int argc, char * argv[])
{
	int kinder_anzahl = 0;

	cout << "Anzahl der Argumente: " << argc << endl;
	
	if (argc < 2) {
		cerr << "Es wurden zu wenige Argumente eingegeben." << endl; // wenn man 2>fehler.txt mit in die console schreibt, wird diese Fehlermeldung in fehler.txt abgespeichert
		kinder_anzahl = hole_kinderzahl();
	}
	else
	{
		kinder_anzahl = stoi(argv[1]);

		if (kinder_anzahl < 1)
		{
			cout << "Geben Sie mindestens 1 Kind ein." << endl;
			return -1;
		}
	}

	//int kinder_anzahl = hole_kinderzahl();
	double kindergeld = berechne_kindergeld(kinder_anzahl);
	ausgabe(kinder_anzahl, kindergeld);
}