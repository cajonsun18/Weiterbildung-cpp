#include <random>
#include <iostream>

using namespace std;

void zieheZahlen(int z[], int max);
int generiereZufallszahl(int min, int max);
void sortierungsBubbleSort(int z[], int z_length);
void ausgabe(int z[], int z_length);

int main()
{
	const int MAX = 6;
	int zahlen[MAX]{};

	for (int i = 0; i < 10; i++)
	{
		// Zieht 6 unterschiedliche Zahlen zwischen 1-49 und speichert sie
		// im Array zahlen ab
		zieheZahlen(zahlen, MAX);

		// Bestimmt die Länge des Arrays
		int zahlen_length = sizeof(zahlen) / sizeof(zahlen[0]);

		//cout << "Vor der Sortierung:" << endl;
		//ausgabe(zahlen, zahlen_length);

		// Sortiert die Zahlen aufsteigend
		sortierungsBubbleSort(zahlen, zahlen_length);

		//cout << endl << endl;
		//cout << "Nach der Sortierung:" << endl;
		cout << i+1 << ". Ziehung:" << endl;
		ausgabe(zahlen, zahlen_length);

		cout << endl << endl;
	}
}

void zieheZahlen(int z[], int max)
{
	for (int i = 0; i < max; i++)
	{
		z[i] = generiereZufallszahl(1, 49);
		for (int k = 0; k < i; k++) 
		{
			if (z[i] == z[k]) {
				i--;
				break;
			}
		}
	}
}

// Generiert eine Zufallszahl zwischen min und max
int generiereZufallszahl(int min, int max)
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> i_bereich(min, max);
	return i_bereich(generator);
}

void sortierungsBubbleSort(int z[], int z_length)
{
	for (int halter = 0; halter < z_length - 1; halter++)
	{
		for (int lfr = halter + 1; lfr < z_length; lfr++)
		{
			if (z[lfr] < z[halter])
			{
				int h = z[lfr];
				z[lfr] = z[halter];
				z[halter] = h;
			}
		}
	}

}

// Gibt jedes Element des Arrays aus.
void ausgabe(int z[], int z_length)
{
	for (int i = 0; i < z_length; i++)
	{
		cout << left << z[i] << " ";
	}
}