#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "de_DE.utf8");

	int breite = 0,
		hoehe = 0,
		tiefe = 0,
		brettstaerke = 0,
		brett_seite_b = 0,
		brett_seite_h = 0,
		brett_seite_t = 0,
		brett_oben_b = 0,
		brett_oben_h = 0,
		brett_oben_t = 0,
		brett_tuer_b = 0,
		brett_tuer_h = 0,
		brett_tuer_t = 0,
		brett_hinten_b = 0,
		brett_hinten_h = 0,
		brett_hinten_t = 3;

	const int tuerabstand = 2;

	cout << "Bitte geben folgende drei Maße ein:" << endl;
	cout << "Breite[mm]: ";
	cin >> breite;
	cout << "Hoehe[mm]: ";
	cin >> hoehe;
	cout << "Tiefe[mm]: ";
	cin >> tiefe;

	cout << "Wie lautet die Brettstärke in mm? ";
	cin >> brettstaerke;

	brett_seite_b = hoehe - (2 * brettstaerke);
	brett_seite_h = tiefe - brettstaerke - brett_hinten_t;
	brett_seite_t = brettstaerke;

	brett_oben_b = breite;
	brett_oben_h = tiefe - brett_hinten_t;
	brett_oben_t = brettstaerke;

	brett_tuer_b = hoehe - 2 * (brettstaerke - tuerabstand);
	brett_tuer_h = (breite / 2) - tuerabstand;
	brett_tuer_t = brettstaerke;

	brett_hinten_b = breite;
	brett_hinten_h = hoehe;

	string seiten = "2 Bretter " + to_string((int)brett_seite_b) + " x "
		+ to_string((int)brett_seite_h) + " x "
		+ to_string((int)brett_seite_t) + " mm (Seiten)";

	string oben = "2 Bretter " + to_string((int)brett_oben_b) + " x "
		+ to_string((int)brett_oben_h) + " x "
		+ to_string((int)brett_oben_t) + " mm (Oben/Unten)";

	string tuer = "2 Bretter " + to_string((int)brett_tuer_b) + " x "
		+ to_string((int)brett_tuer_h) + " x "
		+ to_string((int)brett_tuer_t) + " mm (Tueren)";

	string hinten = "1 Hartfaserplatte " + to_string((int)brett_hinten_b) + " x "
		+ to_string((int)brett_hinten_h) + " x "
		+ to_string((int)brett_hinten_t) + " mm (Rueckwand)";

	cout << seiten << endl
		 << oben << endl
		 << tuer << endl
		 << hinten << endl;
}
