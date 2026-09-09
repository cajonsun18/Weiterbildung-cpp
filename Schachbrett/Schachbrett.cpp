#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	for (int i = 1; i <= 8; i++)
	{
		int row_numbers = i;

		for (int k = 1; k <= 8; k++)
		{
			cout << left << setw(3) << row_numbers;
			row_numbers++;
		}

		cout << endl;
	}
}

