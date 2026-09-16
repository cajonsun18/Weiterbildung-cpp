#include <iostream>

using namespace std;

//void ausgabe(auto ary[], auto anz)   //int *ary
//{
//	for(auto i=0; i < anz; i++)
//		std::cout << ary[i] << std::endl;
//}
void ausgabe(auto *ary, auto anz)   //int *ary
{
	for(auto i=0; i < anz; i++)
	{
		std::cout << ary[i] << std::endl;	//Bevorzugte Schreibweise, weil unten Fehler möglich

		std::cout << *ary+i << std::endl;	//Falsch, dereferenziert immer das 1. Element
		std::cout << *(ary+i) << std::endl;	//Richtig, Anfangsadresse + i x sizeof(Datentyp)
	}
}


int main()
{
	const int MAX = 5;
	//Anlegen und initialisieren
	int z1[MAX];					//5 Elemente mit Müll
	int z2[MAX] {};				//Ohne Zuweisungsoperator =
	int z3[MAX] = {};				//Mit Zuweisungsoperator
	double z4[MAX] = {1.5,2.7,3.2,4.9,5.1};	//5 Elemente mit vollständiger Initialisierung
	int z5[MAX] = {1,2};			//5 Elemente mit teilweiser Init., Rest wir mit 0 initialisiert
	int z6[] = {10,20,30,40,50};		//Anzahl der Elemente wird anhand der Initialierungswerte bestimmt

	//Belegen
	z1[0] = 45;
	z1[2] = 65;
	z1[4] = 76;

	auto i = 0;

	for (int i = 0; i < 5; i++)
	{
		z2[i] = i * 12/7;
	}

	std::cout << z1[0] << std::endl;
	std::cout << z1[1] << std::endl;
	std::cout << z1[2] << std::endl;
	std::cout << z1[3] << std::endl;
	std::cout << z1[4] << std::endl;

	for (auto i = 0; i < 5; i++)
	{
		std::cout << z2[i] << std::endl;
	}

	cout << "Array z4 vor Multiplikation mit 3: " << endl;
	ausgabe(z4, MAX);

	for (auto &z : z4)
	{
		z*=3;
	}


	//cout << "Array z6" << endl;
	//ausgabe(z6, MAX);
	cout << "Array z4 nach Multiplikation mit 3: " << endl;
	//ausgabe(z4, MAX);

	for (auto z : z4)
	{
		std::cout << z << std::endl;
	}
}

