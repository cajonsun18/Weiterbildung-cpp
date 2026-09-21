#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream> 

using namespace std;

int generiereZufallszahl(int min, int max);
void strToUpper(string &suchbegriff);
void anonymisieren(string &str);


int main()
{
    const string dateiname = "Begriffe.txt";

    ifstream eingabedatei;    // Variable für Dateizugriff (einlesen) anlegen
    ofstream ausgabedatei;    // Variable für Dateizugriff (schreiben) anlegen

    //eingabedatei.open(dateiname, ios_base::in);
    //ausgabedatei.open(dateiname, ios_base::app);

    ///////////////////////////////////////////
    // Aufgabe A
    vector<string> vec_string1;

    vec_string1.push_back("Nummer 1");
    vec_string1.push_back("Nummer 2");
    vec_string1.push_back("Nummer 3");
    vec_string1.push_back("Nummer 4");
    vec_string1.push_back("Nummer 5");
    vec_string1.push_back("Nummer 6");
    vec_string1.push_back("Nummer 7");
    vec_string1.push_back("Nummer 8");
    vec_string1.push_back("Nummer 9");
    vec_string1.push_back("Nummer 10");

    ausgabedatei.open(dateiname, ios_base::out);
    if (!ausgabedatei.is_open()) 
    { 
        cout << "Fehlermeldung: Ausgabedatei konnte nicht geöffnet werden";
        eingabedatei.close(); 
        return -2; 
    }

    for (int i = 0; i < vec_string1.size(); i++)
    {
        cout << i << ".Element: " << vec_string1[i] << endl;
        ausgabedatei << vec_string1[i] << '\n';
    }

    ausgabedatei.close();

    ///////////////////////////////////////////
    // Aufgabe B
    eingabedatei.open(dateiname, ios_base::in); //Dateien öffnen
    if (!eingabedatei.is_open())
    {
        cout << "Fehlermeldung: Eingabedatei konnte nicht geöffnet werden" ;
        return -1;
    }

    string text = "Leer String";
    vector<string> vec_string2;

    getline(eingabedatei, text);
    vec_string2.push_back(text);
    while (!eingabedatei.eof())
    {
        getline(eingabedatei, text);
        vec_string2.push_back(text);
    }

    int zufallszahl = generiereZufallszahl(0, 9);
    string suchbegriff = vec_string2[zufallszahl];

    cout << "Der Suchbegriff lautet: " << suchbegriff << endl;

    eingabedatei.close();

    ///////////////////////////////////////////
    // Aufgabe C

    strToUpper(suchbegriff);
    cout << "Der Suchbegriff in Grossbuchstaben: " << suchbegriff << endl;

    ///////////////////////////////////////////
    // Aufgabe Begriff 3

    string anzeigebegriff = suchbegriff;

    anonymisieren(anzeigebegriff);

    cout << "Der Anzeigebegriff lautet: " << anzeigebegriff << endl;

    ///////////////////////////////////////////
    // Aufgabe Begriff 4
}

// Generiert eine Zufallszahl zwischen min und max
int generiereZufallszahl(int min, int max)
{
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> i_bereich(min, max);
    return i_bereich(generator);
}

void strToUpper(string &suchbegriff)
{
    for (int i = 0; i < suchbegriff.length(); i++)
    {
        suchbegriff[i] = toupper(suchbegriff[i]);
    }
    
}

void anonymisieren(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i])) 
        {
            str[i] = '-';
        }
    }

}
