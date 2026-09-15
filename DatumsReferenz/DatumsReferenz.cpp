#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void getDatumElements(const string& datstr, int& tag, int& monat, int& jahr);

int main()
{
    int tag = 0;
    int monat = 0;
    int jahr = 0;

    getDatumElements("14.09.2026", tag, monat, jahr);

    cout << setw(8) << left << "Tag: " << tag << endl;
    cout << setw(8) << left << "Monat: " << monat << endl;
    cout << setw(8) << left << "Jahr: " << jahr << endl;
}

void getDatumElements(const string &datstr, int& tag, int& monat, int& jahr) 
{
    string s_tag = datstr.substr(0, 2);
    tag = stoi(s_tag);

    string s_monat = datstr.substr(4, 2);
    monat = stoi(s_monat);

    string s_jahr = datstr.substr(6, 4);
    jahr = stoi(s_jahr);
}
