#include <random>
#include <iostream>
using namespace std;

#define CLEAR_CIN cin.clear(); cin.ignore(1000, '\n')
#define PAUSE system("pause");
#define CLEAR system("cls");

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "de_DE.utf8");

	const int UNTERGRENZE = 1;
	const int OBERGRENZE = 1000;

	int spieler_anzahl = 0;
	int zufallszahl = 0;
	int rateversuch_zahl = 0;

	bool invalidInput = false;
	bool wants_to_play = true;

	char nochmal_spielen = ' ';

	// Regeln
	cout << "Regeln des Spiels: " << endl;
	cout << "Man kann dieses Spiel mit 1 oder 2 Spielern spielen." << endl;
	cout << "Bei zwei Spielern legt Spieler 1 eine Zahl zwischen 1-1000 fest." << endl;
	cout << "Im Anschluss hat Spieler 2 zehn Versuche, diese Zahl zu erraten." << endl;
	cout << "Bei nur einem Spieler wird die zu ratende Zahl per Zufallsgenerator generiert." << endl;
	cout << "Das Spiel kann jederzeit mit der Eingabe von einer '0' abgebrochen werden." << endl;
	
	while (wants_to_play)
	{
		// Eingabe der Spieleranzahl
		do {
			invalidInput = false;

			cout << "Mit wie vielen Spielern spielen Sie (1 oder 2)?: " << endl;
			cin >> spieler_anzahl;

			// Fehlerhafte Eingabe
			if (cin.fail())
			{
				cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;

				CLEAR_CIN;
				invalidInput = true;
			}
			else if ((spieler_anzahl < 1 || spieler_anzahl > 2) && !(spieler_anzahl == 0)) // Zufallszahl nicht im Bereich
			{
				cout << "Ungültige Eingabe. Die Spieleranzahl muss zwischen 1 und 2 liegen." << endl;

				CLEAR_CIN;
				invalidInput = true;
			}
		} while (invalidInput);

		// Spiel Abbruch
		if (spieler_anzahl == 0)
		{
			cout << "Das Spiel wurde abgebrochen!" << endl;
			break;
		}

		//// Auswertung der Spieleranzahl

		// 1 Spieler
		if (spieler_anzahl == 1)
		{
			// Eine Zufallszahl wird generiert
			random_device rd;
			mt19937 generator(rd());
			uniform_int_distribution<> i_bereich(1, 1000);
			zufallszahl = i_bereich(generator);
		}
		else // 2 Spieler
		{
			// Eingabe der Zufallszahl
			do {
				invalidInput = false;

				cout << "Bitte gib eine Zahl zwischen 1 und 1000 ein: " << endl;
				cin >> zufallszahl;

				// Fehlerhafte Eingabe
				if (cin.fail())
				{
					cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;

					CLEAR_CIN;
					invalidInput = true;
				}
				else if ((zufallszahl < 1 || zufallszahl > 1000) && !(zufallszahl == 0)) // Zufallszahl nicht im Bereich
				{
					cout << "Ungültige Eingabe. Die Zufallszahl muss zwischen 1 und 1000 liegen." << endl;

					CLEAR_CIN;
					invalidInput = true;
				}

			} while (invalidInput);
		}

		// Spiel Abbruch
		if (zufallszahl == 0)
		{
			cout << "Das Spiel wurde abgebrochen!" << endl;
			break;
		}

		PAUSE;
		CLEAR;


		cout << "Die Zufallszahlen lauten: " << zufallszahl << endl;


		// Eingabe der zu ratenden Zahl
		// Auswertung der eigebenen Zahl
		for (int i = 1; i <= 10; i++)
		{

			// Eingabe der zu ratenden Zahl
			do {
				invalidInput = false;

				cout << "Welche Zahl denkst du wurde ausgewählt? Bitte eingeben:" << endl;
				cout << i << ".Versuch: ";
				cin >> rateversuch_zahl;
				cout << endl;

				// Fehlerhafte Eingabe
				if (cin.fail())
				{
					cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;
					CLEAR_CIN;
					invalidInput = true;
				}
				else if ((rateversuch_zahl < 1 || rateversuch_zahl > 1000) && !(rateversuch_zahl == 0)) // Eingabe außerhalb des Bereichs
				{
					cout << "Ungültige Eingabe. Die Zahl muss zwischen 1 und 1000 liegen." << endl;

					CLEAR_CIN;
					invalidInput = true;
				}

			} while (invalidInput);

			// Auswertung der eingegebenen Zahl
			if (rateversuch_zahl == 0)	// Spiel Abbruch
			{
				cout << "Das Spiel wurde abgebrochen!" << endl;
				break;
			}
			else if (rateversuch_zahl == zufallszahl) // Spieler hat die Zahl errraten
			{
				cout << "Herzlichen Glückwunsch. Du hast die Zahl erraten!!" << endl;
				break;
			}
			else if (rateversuch_zahl < zufallszahl) // Die geratene Zahl ist zu klein
			{
				cout << "Die Zahl ist zu klein" << endl;
			}
			else if (rateversuch_zahl > zufallszahl) // Die geratene Zahl ist zu groß
			{
				cout << "Die Zahl ist zu groß" << endl;
			}
		}

		if (rateversuch_zahl != zufallszahl && !(rateversuch_zahl == 0))
		{
			cout << "Du hast leider verloren" << endl;
		}

		cout << "Die gesuchte Zahl lautet: " << zufallszahl << endl;

		// Abfrage, ob das Spiel wiederholt werden soll
		do {
			invalidInput = false;

			cout << "Nochmal spielen (J/N)?" << endl;
			cin >> nochmal_spielen;

			if (tolower(nochmal_spielen) != 'j' && tolower(nochmal_spielen) != 'n')
			{
				cout << "Ungültige Eingabe. Bitte 'J' oder 'N' eingeben" << endl;

				CLEAR_CIN;
				invalidInput = true;
			}
		} while (invalidInput);

		// Abbruch des Spiels, wenn 'n' eingegeben wurde
		if (tolower(nochmal_spielen) == 'n')
		{
			wants_to_play = false;
		}
	}
}
