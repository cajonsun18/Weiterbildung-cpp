
#include <iostream>

using namespace std;

int main()
{
	enum Wochentage
	{
		Montag = 1,
		Dienstag = 2,
		Mittwoch = 3,
		Donnerstag = 4,
		Freitag = 5,
		Samstag = 6,
		Sonntag = 7
	};
	Wochentage heute = Wochentage::Donnerstag;
	Wochentage tag = Wochentage::Montag;
	int zahl = 0;

	cout << "Heute ist der " << heute << ".Tag" << endl;

	cout << "Gebe Sie einen Tag ein (1-7): ";
	cin >> zahl;
	tag = static_cast<Wochentage>(zahl);

	cout << "Der eingegebene Tag ist: " << tag << endl;
}