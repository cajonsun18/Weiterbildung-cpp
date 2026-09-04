#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	enum MenuStatus
	{
		Rueckgaengig = 1,
		Wiederholen = 2,
		Ausschneiden = 4,
		Kopieren = 8,
		Einfuegen = 16
	};

	MenuStatus status;
	status = (MenuStatus) (Rueckgaengig | Einfuegen);
	cout << "Status: " << bitset<8>(status) << endl;

	status = (MenuStatus) (Ausschneiden | Kopieren | Einfuegen);
	cout << "Status: " << bitset<8>(status) << endl;
}
