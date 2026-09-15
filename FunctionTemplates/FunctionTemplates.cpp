// FunctionTemplates.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
void tausch(T &a, T &b) //Bestehende Datentypen werden nun durch T ausgetauscht.
{
    T h = a;
    a = b;
    b = h;
}

template<class T>
T min(T &a, T &b)
{
    return (a < b) ? a : (a > b) ? b : 0;
}


int main()
{
    int i_x = 7, i_y = 2;
    char c_c = 'E', c_d = 'N';
    double d_f = 3.744, d_g = 8.474;

    cout << "Vor Tausch" << endl;
    cout << left << setw(10) << "Int X: " << i_x << ", Int Y: " << i_y << endl;
    cout << left << setw(10) << "Char C: " << c_c << ", Char D: " << c_d << endl;
    cout << left << setw(10) << "Double F: " << d_f << ", Double G: " << d_g << endl;
    
    tausch<int>(i_x, i_y); // Die spitzen Klammern mit Datentyp sind optional
    tausch<char>(c_c, c_d);
    tausch<double>(d_f, d_g);

    cout << endl;
    cout << "-----------------------------------" << endl;
    cout << "Nach Tausch" << endl;
    cout << left << setw(10) << "Int X: " << i_x << ", Int Y: " << i_y << endl;
    cout << left << setw(10) << "Char C: " << c_c << ", Char D: " << c_d << endl;
    cout << left << setw(10) << "Double F: " << d_f << ", Double G: " << d_g << endl;


    int i_wert = min<int>(i_x, i_y);
    char c_wert = min<char>(c_c, c_d);
    double d_wert = min<double>(d_f, d_g);

    cout << endl;
    cout << "-----------------------------------" << endl;
    cout << "Min Wert" << endl;
    cout << left << setw(10) << "Min Integer von X: " << i_x << " und Y: " << i_y << " ist: " << i_wert << endl;
    cout << left << setw(10) << "Min Char von C: " << c_c << " und D: " << c_d << " ist: " << c_wert << endl;
    cout << left << setw(10) << "Min Double von F: " << d_f << " und G: " << d_g << " ist: " << d_wert << endl;
}