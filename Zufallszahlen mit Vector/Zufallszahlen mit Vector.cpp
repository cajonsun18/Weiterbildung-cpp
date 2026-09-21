#include <random>
#include <iostream>
#include <iomanip>

using namespace std;

int generiereZufallszahl(int min, int max);
void sortierungsBubbleSort(vector<int> &vec);
void ausgabe(const vector<int>& vec);

int main()
{
	vector<int> vec_zahlen(200);

	// Generiert 200 Zufallszahlen und speichert sie im Array zahlen ab
	for (int i = 0; i < 200; i++)
	{
		vec_zahlen[i] = generiereZufallszahl(1, 100);
	}

	cout << "Vor der Sortierung:" << endl;
	ausgabe(vec_zahlen);

	sortierungsBubbleSort(vec_zahlen);

	cout << "Nach der Sortierung:" << endl;
	ausgabe(vec_zahlen);
}

// Generiert eine Zufallszahl zwischen min und max
int generiereZufallszahl(int min, int max)
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> i_bereich(min, max);
	return i_bereich(generator);
}

void sortierungsBubbleSort(vector<int> &vec)
{
	for (int halter = 0; halter < vec.size() - 1; halter++)
	{
		for (int lfr = halter + 1; lfr < vec.size(); lfr++)
		{
			if (vec[lfr] > vec[halter])
			{
				int h = vec[lfr];
				vec[lfr] = vec[halter];
				vec[halter] = h;
			}
		}
	}

}

// Gibt jedes Element des vectors aus. 20 Werte pro Zeile
void ausgabe(const vector<int> &vec)
{
	for (int i = 0; i < vec.size(); i += 20)
	{
		for (int k = i; k < i + 20; k++)
		{
			cout << left << setw(5) << vec[k];
		}

		cout << endl;
	}
}