#include <iostream>

using namespace std;

void tausch(int &x, int &y)
{
    cout << "----------------" << endl;
    cout << "Vor Tausch von X und Y: " << endl;
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;

    int h = x;
    x = y;
    y = h;

    cout << "Nach Tausch von X und Y: " << endl;
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;
}

int main()
{
    int a = 13;
    int b = 80;

    cout << "Vor Tausch von A und B: " << endl;
    cout << "A: " << a << endl;
    cout << "B: " << b << endl;

    tausch(a, b);

    cout << "----------------" << endl;
    cout << "Nach Tausch von A und B: " << endl;
    cout << "A: " << a << endl;
    cout << "B: " << b << endl;
}
