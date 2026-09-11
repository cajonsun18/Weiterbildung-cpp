#include <random>
#include <iostream>
#include <string>

using namespace std;

#define CLEAR_CIN cin.clear(); cin.ignore(1000, '\n')
#define PAUSE system("pause");
#define CLEAR system("cls");

// Erklärung der Spielregeln
void spielregeln() {
	cout << "\t\t\t SPIELREGELN " << endl;
	cout << "- Man kann dieses Spiel mit 1 oder 2 Spielern spielen." << endl;
	cout << "- Bei zwei Spielern legt Spieler 1 eine Zahl zwischen 1-1000 fest." << endl;
	cout << "- Im Anschluss hat Spieler 2 zehn Versuche, diese Zahl zu erraten." << endl;
	cout << "- Bei nur einem Spieler wird die zu ratende Zahl per Zufallsgenerator generiert." << endl;
	cout << "- Das Spiel kann jederzeit mit der Eingabe von einer '0' abgebrochen werden." << endl << endl;

}

// Zahleneingabe über die Console
int consoleEingabe(string frage, string fehlertext, int min, int max)
{
	int zahl = 0;
	bool invalidInput = true;

	while(invalidInput) 
	{
		invalidInput = false;

		cout << frage << endl;
		cin >> zahl;

		// Fehlerhafte Eingabe
		if (cin.fail())
		{
			cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;

			CLEAR_CIN;
			invalidInput = true;
		}
		else if ((zahl < min || zahl > max) && !(zahl == 0)) // Zahl nicht im Bereich
		{
			cout << fehlertext << endl;

			CLEAR_CIN;
			invalidInput = true;
		}
	} 

	return zahl;
}

// Generiert eine Zufallszahl
int generiereZufallszahl(int min, int max)
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> i_bereich(min, max);
	return i_bereich(generator);
}

// Überprüft, ob die geratene Zahl gleich der Zufallszahl ist
bool auswertungEingabe(int rateversuch_zahl, int zufallszahl) 
{
	if (rateversuch_zahl == 0)	// Spiel Abbruch
	{
		cout << "Das Spiel wurde abgebrochen!" << endl;
		return true;
	}
	else if (rateversuch_zahl == zufallszahl) // Spieler hat die Zahl errraten
	{
		return true;
	}
	else if (rateversuch_zahl < zufallszahl) // Die geratene Zahl ist zu klein
	{
		cout << "Die Zahl ist zu klein" << endl;
		return false;
	}
	else if (rateversuch_zahl > zufallszahl) // Die geratene Zahl ist zu groß
	{
		cout << "Die Zahl ist zu groß" << endl;
		return false;
	}
	return false;
}

int raten(int zufallszahl)
{
	int rateversuch_zahl = 0;

	//// Eingabe der zu ratenden Zahl
	// Auswertung der eigebenen Zahl
	for (int i = 1; i <= 10; i++)
	{

		// Eingabe der zu ratenden Zahl
		string frage = "Welche Zahl denkst du wurde ausgewählt? Bitte eingeben: \n" +
			to_string(i) + ".Versuch: ";
		string fehlertext = "Ungültige Eingabe. Die Zahl muss zwischen 1 und 1000 liegen.";
		rateversuch_zahl = consoleEingabe(frage, fehlertext, 1, 1000);

		// Auswertung der eingegebenen Zahl
		bool spiel_beendet = auswertungEingabe(rateversuch_zahl, zufallszahl);

		if (spiel_beendet)
		{
			break;
		}
	}

	return rateversuch_zahl;
}

// Gibt aus, ob man gewonnen oder verloren hat
void ausgabeErgebnis(int rateversuch_zahl, int zufallszahl)
{
	if (rateversuch_zahl != zufallszahl && !(rateversuch_zahl == 0))
	{
		cout << "Du hast leider verloren" << endl;
		cout << "Die gesuchte Zahl lautet: " << zufallszahl << endl;
	}
	else if (rateversuch_zahl == zufallszahl)
	{
		cout << "Herzlichen Glückwunsch. Du hast die Zahl erraten!!" << endl;
		cout << "Die gesuchte Zahl lautet: " << zufallszahl << endl;
	}
}

// Fragt, ob man ein weiteres Spiel spielen möchte
bool abfrageSpielWiederholen()
{
	bool invalidInput = true;
	char nochmal_spielen = ' ';

	// Abfrage, ob das Spiel wiederholt werden soll
	while (invalidInput) {
		invalidInput = false;

		cout << "Nochmal spielen (J/N)?" << endl;
		cin >> nochmal_spielen;

		if (tolower(nochmal_spielen) != 'j' && tolower(nochmal_spielen) != 'n')
		{
			cout << "Ungültige Eingabe. Bitte 'J' oder 'N' eingeben" << endl;

			CLEAR_CIN;
			invalidInput = true;
		}
	}

	// Weiterspielen bei 'j'
	if (tolower(nochmal_spielen) == 'j')
	{
		return true;
	}

	return false;
}

// Überprüft, ob das Spiel abgebrochen worden ist
bool istSpielbeendet(int zahl)
{
	if (zahl == 0)
	{
		cout << "Das Spiel wurde abgebrochen!" << endl;
		return true;
	}

	return false;
}

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "de_DE.utf8");

	//// Variablendeklaration
	int spieler_anzahl = 0;
	int zufallszahl = 0;
	int rateversuch_zahl = 0;
	bool wants_to_play = true;

	//// Ausgabe der Spielregeln
	spielregeln();
	
	// Spielloop
	while (wants_to_play)
	{

		//// Eingabe der Spieleranzahl
		string frage = "Mit wie vielen Spielern spielen Sie (1 oder 2)?: ";
		string fehlertext = "Ungültige Eingabe. Die Spieleranzahl muss zwischen 1 und 2 liegen.";
		spieler_anzahl = consoleEingabe(frage, fehlertext, 1, 2);

		// Spiel Abbruch
		if (istSpielbeendet(spieler_anzahl)) {
			break;
		}

		//// Auswertung der Spieleranzahl

		// 1 Spieler
		if (spieler_anzahl == 1)
		{
			// Eine Zufallszahl wird generiert
			zufallszahl = generiereZufallszahl(1, 1000);
		}
		else // 2 Spieler
		{
			// Eingabe der Zufallszahl
			string frage = "Bitte gib eine Zahl zwischen 1 und 1000 ein: ";
			string fehlertext = "Ungültige Eingabe. Die Zufallszahl muss zwischen 1 und 1000 liegen.";
			zufallszahl = consoleEingabe(frage, fehlertext, 1, 1000);
		}

		// Spiel Abbruch
		if (istSpielbeendet(zufallszahl)) {
			break;
		}

		PAUSE;
		CLEAR;

		cout << "Die Zufallszahlen lauten: " << zufallszahl << endl;


		// Zahl raten
		rateversuch_zahl = raten(zufallszahl);

		// Ausgabe des Ergebnisses
		ausgabeErgebnis(rateversuch_zahl, zufallszahl);

		// Abfrage, ob ein weiteres Spiel gespielt werden möchte
		wants_to_play = abfrageSpielWiederholen();
	}
}