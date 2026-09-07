#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "de_DE.utf8");

	int breite = 0,
		hoehe = 0,
		tiefe = 0,
		brettstaerke_wand_und_boden = 0,
		brettstaerke_deckplatte = 0,
		brettstaerke_tuer = 0,
		brett_seite_b = 0,
		brett_seite_h = 0,
		brett_seite_t = 0,
		brett_oben_b = 0,
		brett_oben_h = 0,
		brett_oben_t = 0,
		brett_unten_b = 0,
		brett_unten_h = 0,
		brett_unten_t = 0,
		brett_tuer_b = 0,
		brett_tuer_h = 0,
		brett_tuer_t = 0,
		brett_hinten_b = 0,
		brett_hinten_h = 0,
		brett_hinten_t = 3;

	char bodentyp = ' ',
		 tuertyp = ' ';

	const int TUERABSTAND = 2,
			  BRETTSTAERKE_WB_LOWERLIMIT = 16,
			  BRETTSTAERKE_WB_UPPERLIMIT = 50,
			  BRETTSTAERKE_DECK_UPPERLIMIT = 70,
			  BRETTSTAERKE_TUER_LOWERLIMIT = 12,
			  BRETTSTAERKE_TUER_UPPERLIMIT = 19;

	cout << "Bitte geben folgende drei Maße ein:" << endl;
	cout << "Breite[mm]: ";
	cin >> breite;

	if (cin.fail())
	{
		cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;
		return -1;
	}

	cout << "Hoehe[mm]: ";
	cin >> hoehe;

	if (cin.fail())
	{
		cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;
		return -1;
	}

	cout << "Tiefe[mm]: ";
	cin >> tiefe;

	if (cin.fail())
	{
		cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;
		return -1;
	}

	cout << "Wie lautet die Brettstärke der Wände und Boden in mm [16-50mm]? ";
	cin >> brettstaerke_wand_und_boden;

	if (cin.fail())
	{
		cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;
		return -1;
	}
	else if (brettstaerke_wand_und_boden < BRETTSTAERKE_WB_LOWERLIMIT ||
		brettstaerke_wand_und_boden > BRETTSTAERKE_WB_UPPERLIMIT)
	{
		cout << "Ungültige Eingabe. Eingabe befindet sich außerhalb des erlaubten Bereichs." << endl;
		return -1;
	}

	cout << "Ist der Boden eingesetzt oder aufgesetzt [e/a]? ";
	cin >> bodentyp;

	if (tolower(bodentyp) != 'e' && tolower(bodentyp) != 'a')
	{
		cout << "Ungültige Eingabe. Nicht e oder a eingegeben." << endl;
		return -1;
	}

	cout << "Wie hoch ist die aufgesetzte Deckplatte [" << brettstaerke_wand_und_boden << "-70mm]? ";
	cin >> brettstaerke_deckplatte;

	if (cin.fail())
	{
		cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;
		return -1;
	}
	else if (brettstaerke_deckplatte < brettstaerke_wand_und_boden ||
		brettstaerke_deckplatte > BRETTSTAERKE_DECK_UPPERLIMIT)
	{
		cout << "Ungültige Eingabe. Eingabe befindet sich außerhalb des erlaubten Bereichs." << endl;
		return -1;
	}

	cout << "Sind die Türen eingesetzt oder aufgesetzt [e/a]? ";
	cin >> tuertyp;

	if (tolower(tuertyp) != 'e' && tolower(tuertyp) != 'a')
	{
		cout << "Ungültige Eingabe. Nicht e oder a eingegeben." << endl;
		return -1;
	}

	cout << "Welche Stärke haben die Türen [12-19mm]? ";
	cin >> brettstaerke_tuer;

	if (cin.fail())
	{
		cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;
		return -1;
	}
	else if (brettstaerke_tuer < BRETTSTAERKE_TUER_LOWERLIMIT ||
		brettstaerke_tuer > BRETTSTAERKE_TUER_UPPERLIMIT)
	{
		cout << "Ungültige Eingabe. Eingabe befindet sich außerhalb des erlaubten Bereichs." << endl;
		return -1;
	}

	/////// Seitenbretter
	
	// Seitenbretter Breite
	if (bodentyp == 'a')
	{
		brett_seite_b = hoehe - brettstaerke_wand_und_boden - brettstaerke_deckplatte;
	}
	else
	{
		brett_seite_b = hoehe - brettstaerke_deckplatte;
	}

	// Seitenbretter Höhe
	if (tuertyp == 'a')
	{
		brett_seite_h = tiefe - brettstaerke_tuer - brett_hinten_t;
	}
	else
	{
		brett_seite_h = tiefe - brett_hinten_t;
	}

	// Seitenbretter Tiefe
	brett_seite_t = brettstaerke_wand_und_boden;

	/////// Bodenbrett

	// Bodenbrett Breite
	if (bodentyp == 'a')
	{
		brett_unten_b = breite;
	}
	else
	{
		brett_unten_b = breite - (2 * brettstaerke_wand_und_boden);
	}

	// Bodenbrett Höhe
	if (tuertyp == 'a')
	{
		brett_unten_h = tiefe - brettstaerke_tuer - brett_hinten_t;
	}
	else
	{
		brett_unten_h = tiefe - brett_hinten_t;
	}

	// Bodenbrett Tiefe
	brett_unten_t = brettstaerke_wand_und_boden;

	// Deckplatte
	brett_oben_b = breite;					// Deckplatte Breite
	brett_oben_h = tiefe - brett_hinten_t;	// Deckplatte Höhe
	brett_oben_t = brettstaerke_deckplatte;	// Deckplatte Tiefe

	/////// Türen

	// Türen Breite
	if (tuertyp == 'a')
	{
		brett_tuer_b = hoehe - brettstaerke_deckplatte - (2 * TUERABSTAND);
	}
	else
	{
		brett_tuer_b = hoehe - brettstaerke_deckplatte - brettstaerke_wand_und_boden - (2 * TUERABSTAND);
	}

	// Türen Höhe
	if (tuertyp == 'a')
	{
		brett_tuer_h = (breite / 2) - TUERABSTAND;
	}
	else
	{
		brett_tuer_h = (breite / 2) - (2 * brettstaerke_wand_und_boden) - TUERABSTAND;
	}

	// Türen Tiefe
	brett_tuer_t = brettstaerke_tuer;

	brett_hinten_b = breite;
	brett_hinten_h = hoehe;

	string seiten = "2 Bretter " + to_string((int)brett_seite_b) + " x "
		+ to_string((int)brett_seite_h) + " x "
		+ to_string((int)brett_seite_t) + " mm (Seiten)";

	string oben = "1 Brett " + to_string((int)brett_oben_b) + " x "
		+ to_string((int)brett_oben_h) + " x "
		+ to_string((int)brett_oben_t) + " mm (Oben)";

	string unten = "1 Brett " + to_string((int)brett_unten_b) + " x "
		+ to_string((int)brett_unten_h) + " x "
		+ to_string((int)brett_unten_t) + " mm (Unten)";

	string tuer = "2 Bretter " + to_string((int)brett_tuer_b) + " x "
		+ to_string((int)brett_tuer_h) + " x "
		+ to_string((int)brett_tuer_t) + " mm (Tueren)";

	string hinten = "1 Hartfaserplatte " + to_string((int)brett_hinten_b) + " x "
		+ to_string((int)brett_hinten_h) + " x "
		+ to_string((int)brett_hinten_t) + " mm (Rueckwand)";

	cout << seiten << endl
		<< oben << endl
		<< unten << endl
		<< tuer << endl
		<< hinten << endl;
}
