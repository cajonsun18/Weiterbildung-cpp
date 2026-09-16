#include <random>
#include <iostream>
#include <iomanip>

using namespace std;

int generiereZufallszahl(int min, int max);
void ausgabe(int z[], int z_length);

int main()
{
	int zahlen[200]{};

	// Generiert 200 Zufallszahlen und speichert sie im Array zahlen ab
	for (int i = 0; i < 200; i++)
	{
		zahlen[i] = generiereZufallszahl(1, 100);
	}

	// Bestimmt die Länge des Arrays
	int zahlen_length = sizeof(zahlen) / sizeof(zahlen[0]);

	ausgabe(zahlen, zahlen_length);
}

// Generiert eine Zufallszahl zwischen min und max
int generiereZufallszahl(int min, int max)
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> i_bereich(min, max);
	return i_bereich(generator);
}

// Gibt jedes Element des Arrays aus. 20 Werte pro Zeile
void ausgabe(int z[], int z_length)
{
	for (int i = 0; i < z_length; i+=20)
	{
		for (int k = i; k < i+20; k++)
		{
			cout << left << setw(5) << z[k];
		}

		cout << endl;
	}
}