#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name = " ", 
           passwort_eingabe = " ";
    const string NUTZERNAME = "Peter",
           PASSWORT = "1234";

    setlocale(LC_ALL, "de_DE.utf8");
    cout << "Geben Sie einen Benutzernamen und Passwort ein: " << endl;
    cout << "Benutzername: ";
    cin >> name;
    cout << "Passwort: ";
    cin >> passwort_eingabe;

    if (name == NUTZERNAME && passwort_eingabe == PASSWORT)
    {
        cout << "Genehmigt";
    }
    else
    {
        cout << "Verweigert";
    }
}