#include <iostream>
#include <string>

using namespace std;

// funktions-prototypen
void Eingabe(string meldetext, double *wert);
void Flaeche(double *laenge, double *breite, double *ergebnis);
void Volumen(double *laenge, double *breite, double *hoehe, double *ergebnis);
void Ausgabe(double *flaeche, double *volumen);

int main()
{
    double laenge = 0, breite = 0, hoehe = 0;
    double flaeche = 0, volumen = 0;

    // E)ingabe
    Eingabe("Laenge: ", &laenge);
    Eingabe("Breite: ", &breite);
    Eingabe("Hoehe: ", &hoehe);

    // V)erarbeitung
    Flaeche(&laenge, &breite, &flaeche);
    Volumen(&laenge, &breite, &hoehe, &volumen);

    // A)usgabe
    Ausgabe(&flaeche, &volumen);

    return 0;
}

// wert ueber zeiger einlesen
void Eingabe(string meldetext, double* wert)
{
    cout << meldetext;
    cin >> *wert;
}

// flaeche ueber zeiger berechnen
void Flaeche(double *laenge, double *breite, double *ergebnis)
{
    *ergebnis = (*laenge) * (*breite);
}

// volumen ueber zeiger berechnen
void Volumen(double *laenge, double *breite, double *hoehe, double *ergebnis)
{
    *ergebnis = (*laenge) * (*breite) * (*hoehe);
}

// ergebnisse ueber zeiger ausgeben
void Ausgabe(double *flaeche, double *volumen)
{
    cout << "Flaeche: " << *flaeche << endl;
    cout << "Volumen: " << *volumen << endl;
}