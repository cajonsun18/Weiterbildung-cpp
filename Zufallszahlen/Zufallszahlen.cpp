#include <iostream>
using namespace std;

int main()
{
	srand(time(NULL));

	int untergrenze = 0, 
		obergrenze = 0, 
		zufallszahl = 0;

    cout << "Geben Sie eine Unter- und Obergrenze an: " << endl;
	cout << "Untergrenze: ";
	cin >> untergrenze;
	cout << "Obergrenze: ";
	cin >> obergrenze;

	cout << "Die Zufallszahlen lauten: " << endl;

	for (int i = 1; i <= 100; i++)
	{
		zufallszahl = (rand() % (obergrenze - untergrenze)) + 1 + untergrenze;

		cout << zufallszahl << " ";
		if (i % 10 == 0) 
		{
			cout << endl;
		}

	}
}
