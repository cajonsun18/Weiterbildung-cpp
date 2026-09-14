#include <random>
#include <iostream>
#include <string>

using namespace std;

#define CLEAR_CIN cin.clear(); cin.ignore(1000, '\n')

int consoleEingabe(string text);
int generiereZufallszahl(int max = 1000, int min = 1);
void ausgabe(int zufallszahl1, int zufallszahl2, int zufallszahl3);

int main()
{
	srand((unsigned)time(NULL));

	int untergrenze = 0,
		obergrenze = 0,
		zufallszahl1 = 0,
		zufallszahl2 = 0,
		zufallszahl3 = 0;

	cout << "Bitte gib die Ober- und Untergrenze deiner Zufallszahl ein: " << endl;
	untergrenze = consoleEingabe("Untergrenze");
	obergrenze = consoleEingabe("Obergrenze");

	zufallszahl1 = generiereZufallszahl();
	zufallszahl2 = generiereZufallszahl(obergrenze);
	zufallszahl3 = generiereZufallszahl(obergrenze, untergrenze);

	ausgabe(zufallszahl1, zufallszahl2, zufallszahl3);
}

int consoleEingabe(string text)
{
	int zahl;
	bool invalidInput = true;

	while (invalidInput)
	{
		invalidInput = false;

		cout << text << ": ";
		cin >> zahl;

		// Fehlerhafte Eingabe
		if (cin.fail())
		{
			cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;

			CLEAR_CIN;
			invalidInput = true;
		}
	}

	return zahl;
}

// Generiert eine Zufallszahl zwischen min und max
int generiereZufallszahl(int max, int min)
{
	return rand() % (max - min + 1) + min;
}

void ausgabe(int zufallszahl1, int zufallszahl2, int zufallszahl3)
{
	cout << "Die Zufallszahlen lauten: " << endl
		<< "Zufallszahl 1: " << zufallszahl1 << endl
		<< "Zufallszahl 2: " << zufallszahl2 << endl
		<< "Zufallszahl 3: " << zufallszahl3 << endl;
}
