#include <iostream>

using namespace std;

int main()
{
    int zahl = 5;           // Variable anlegen
    int &rzahl = zahl;      // Referenz anlegen
    int *ptr1 = nullptr;    // Zeiger anlegen

    zahl = 10;              // Wert zuweisen
    rzahl = 20;             // Wert zuweisen
    ptr1 = &zahl;           // Adresse zuweisen
    *ptr1 = 30;             // Zeiger dereferenzieren und Wert, der referenzierten Variablen zuweisen
    int zahl2 = 100;        // Wert zuweisen
    rzahl = zahl2;          // Wert zuweisen
    ptr1 = &zahl2;          // Adresse zuweisen

    *ptr1 = 200;            // Zeiger dereferenzieren und Wert, der referenzierten Variablen zuweisen
    ptr1 = nullptr;         // Zeiger leeren (Zeiger verweist auf nichts)

    if (!ptr1)              //if (ptr1 == nullptr)      | Ist der Zeiger leer (Verweist er auf nichts?)
        ptr1 = &zahl;

    cout << "Adresse, die der Pointer haelt: " << ptr1 << endl;
    cout << "Wert der Variablen, die der Pointer haelt: " << *ptr1 << endl;
    cout << "Die Adresse des Pointers selbst: " << &ptr1 << endl;

    ////////////////////////////////////////////////////////
    // Dynamischer Speicher
    int *ptr2 = nullptr;
    int zahl = 5;

    *ptr2 = 50;             // zahl = 50
    ptr2 = nullptr;         // Adresse im Pointer wird gelöscht

    ptr2 = new int(100);    // Int-Speicher im Heap anfordern und mit 100 initialisieren
    ptr2 = nullptr;         // Adresse im Pointer wird gelöscht
}

