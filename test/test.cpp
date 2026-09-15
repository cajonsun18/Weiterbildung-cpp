#include "D:/C++/Weiterbildung/MyLib/MyLib.h"

#include <iostream>
using namespace std;

int main()
{
    init();
    int iZahl = getIntZahl("Gebe eine Int Zahl ein (0-1000): ", 0, 1000);
    double dZahl = getDblZahl("Gebe eine Double Zahl ein (0-1000): ", 0, 1000);
    cout << "Die Int Zahl lautet: " << iZahl << endl;
    cout << "Die Double Zahl lautet: " << dZahl << endl;
}