
#include <iostream>
#include <limits>

using namespace std;

int x;

int main()
{
	cout << "Untere Grenze von int: "
		<< numeric_limits<int>::min() << endl;
	cout << "Oberste Grenze von int: "
		<< numeric_limits<int>::max() << endl;
	cout << "Untere Grenze von uint: "
		<< numeric_limits<unsigned int>::min() << endl;
	cout << "Oberste Grenze von uint: "
		<< numeric_limits<unsigned int>::max() << endl;
	cout << "Untere Grenze mit min() von double: "
		<< numeric_limits<double>::min() << endl;
	cout << "Oberste Grenze mit max() von double: "
		<< numeric_limits<double>::max() << endl;
	cout << "Untere Grenze mit lowest() von double: "
		<< numeric_limits<double>::lowest() << endl;

	cout << "INT = " << sizeof(int) << " Bytes" << endl;
	cout << "UINT = " << sizeof(unsigned int) << " Bytes" << endl;
	cout << "DOUBLE = " << sizeof(double) << " Bytes" << endl;

	cout << "x = " << sizeof(x) << " Bytes" << endl;
}