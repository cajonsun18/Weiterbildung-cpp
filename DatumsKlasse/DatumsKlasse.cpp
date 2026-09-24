#include <iostream>
#include "datum.h"

using namespace std;

int main()
{
    try
    {
        Datum datum1;
        cout << datum1.toString() << endl;
    }
    catch (const exception& ex)
    {
        cout << "Fehler: " << ex.what() << endl;
    }
    catch (...)
    {
        cout << "Fehler nicht lokalisierbar." << endl;
    }
}