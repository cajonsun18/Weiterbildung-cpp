#include <iostream>
#include <string>

using namespace std;

int main()
{
	int tag = 0, 
		monat = 0, 
		jahr = 0;

	cout << "Geben sie ein Datum ein (Tag, Monat, Jahr): " << endl;
	cout << "Tag: ";
	cin >> tag;
	cout << "Monat: ";
	cin >> monat;
	cout << "Jahr: ";
	cin >> jahr;

	string datum = ((tag < 10) ? "0" : "") + to_string(tag) + "." +
		((monat < 10) ? "0" : "") + to_string(monat) + "." + 
		to_string(jahr);

	cout << "Datum: " << datum << std::endl;
}