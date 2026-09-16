#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "de_DE.utf8");
    int zahl1[5];
    zahl1[0] = 1;
    zahl1[1] = 9;
    zahl1[2] = 6;
    zahl1[3] = 473;
    zahl1[4] = -1;

    cout << "Die Werte des Arrays sind: " << endl
        << "zahl[0]: " << zahl1[0] << endl
        << "zahl[1]: " << zahl1[1] << endl
        << "zahl[2]: " << zahl1[2] << endl
        << "zahl[3]: " << zahl1[3] << endl
        << "zahl[4]: " << zahl1[4] << endl
        << "Sizeof(zahl): " << sizeof(zahl1) << endl
        << "Sizeof(zahl[0]): " << sizeof(zahl1[0]) << endl;

    //////////////////////////////////////////////////

    int zahl2[5];
    int zahl2_length = sizeof(zahl2) / sizeof(zahl2[0]);

    cout << endl;
    cout << "Bitte gib Zahlen für die Elemente des Arrays an: " << endl;
    for (int i = 0; i < zahl2_length; i++)
    {
        cout << "zahl2[" << i << "]: ";
        cin >> zahl2[i];
    }

    cout << endl;
    cout << "Die Zahlen des Array zahl2 lauten: " << endl;

    int* start_zahl2 = zahl2; // oder &zahl2[0]
    int* ende_zahl2 = start_zahl2 + sizeof(zahl2) / sizeof(zahl2[0]);
    int index = 0;
    for (int* p = start_zahl2; p < ende_zahl2; p++)
    {
        cout << "zahl2[" << index++ << "]: " << *p << endl;
    }

    //////////////////////////////////////////////////
    index = 0;
    int zahl3[5] = { 5,3,2,8,12};
    
    cout << endl;
    cout << "Die Zahlen des Array zahl3 lauten: " << endl;
    for (auto x : zahl3)
    {
        cout << "zahl3[" << index++ << "]: " << x << endl;
    }

    //////////////////////////////////////////////////  
    for (int i = 0; i < zahl2_length; i++)
    {
        zahl2[i] = zahl1[i];
    }

    cout << endl;
    cout << "Die Zahlen der Arrays zahl1 und zahl2 lauten: " << endl;
    for (int i = 0; i < zahl2_length; i++)
    {
        cout << "zahl1[" << i << "]: "<< zahl1[i] << "; "
             << "zahl2[" << i << "]: "<< zahl2[i] << endl;
    }
}