#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	char ch = 'A';

	cout << "Buchstabe von ch: " << ch << ", ASCII-Wert: " << (int)ch << endl;
	cout << "Bitanzeige von ch: " << bitset<8>(ch) << endl;
	cout << "Bitanzeige von 32: " << bitset<8>(32) << endl;
	ch |= 32; // Setze das 6. Bit auf 1, um den Buchstaben in Kleinbuchstaben zu ändern
	cout << "Bitanzeige neu von ch: " << bitset<8>(ch) << endl;
	cout << "Buchstabe neu von ch " << ch << ", ASCII-Wert: " << (int)ch << endl;
	cout << "Komplement von 32: " << bitset<8>(~32) << endl;
	ch &= ~32; // Setze das 6. Bit auf 0, um den Buchstaben wieder in Großbuchstaben zu ändern

	cout << "Bitanzeige neu von ch: " << bitset<8>(ch) << endl;
	cout << "Buchstabe neu von ch " << ch << ", ASCII-Wert: " << (int)ch << endl;
}