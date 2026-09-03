#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "de_DE.utf8");

	int laenge = 0,
		breite = 0,
		hoehe = 0;
		
	long volumen = 0;

	double liter = 0.0,
		dosierung_mittel = 0.0,
		dosierung_aquarium = 0.0,
		end_dosierung = 0.0;


	cout << "Bitte geben folgende drei Maße ein:" << endl;
	cout << "Laenge: ";
	cin >> laenge;
	cout << "Breite: ";
	cin >> breite;
	cout << "Hoehe: ";
	cin >> hoehe;

	cout << "Wie lautet die Dosierung?" << endl;
	cout << "Anti-Algenmittel: ";
	cin >> dosierung_mittel;
	cout << "Aquarium: ";
	cin >> dosierung_aquarium;


	volumen = laenge * breite * hoehe;
	liter = volumen / 1000.0;

	end_dosierung = (liter / dosierung_aquarium) * dosierung_mittel;

	string ergebnis = "Sie benoetigen fuer " + to_string((int)liter) + " Liter, "
		+ to_string((int)end_dosierung) + " ml des Mittels.";
	cout << ergebnis << endl;

	cout << fixed << setprecision(2)
		<< "Alternativ mit cout: Sie benoetigen fuer " << liter << " Liter, "
		<< end_dosierung << " ml des Mittels." << endl;
}