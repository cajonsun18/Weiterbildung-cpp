#include <iostream>
using namespace std;

int main()
{
	double celsius = 0, fahrenheit = 0;

	cout << "Bitte einen Celsius-Wert eingeben:";
	cin >> celsius;

	fahrenheit = (celsius * 9 / 5) + 32;

	cout << celsius << " Grad Celsius entsprechen " << fahrenheit << " Grad Fahrenheit." << endl;
}