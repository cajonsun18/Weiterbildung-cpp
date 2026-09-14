#include "funktionen.h"

int main() 
{
	int untergrenze = 0;
	int obergrenze = 0;
	int	zufallszahl1 = 0;
	int	zufallszahl2 = 0;
	int	zufallszahl3 = 0;


	untergrenze = consoleEingabe("Gib eine Untergrenze an: ");
	obergrenze = consoleEingabe("Gib eine Obergrenze an: ");

	zufallszahl1 = generiereZufallszahl();
	zufallszahl2 = generiereZufallszahl(obergrenze);
	zufallszahl3 = generiereZufallszahl(untergrenze, obergrenze);

	ausgabe(zufallszahl1, zufallszahl2, zufallszahl3);
}