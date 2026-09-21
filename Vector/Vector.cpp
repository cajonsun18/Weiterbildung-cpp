#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

using namespace std;

int generiereZufallszahl(int min, int max);
void sortierungsBubbleSort(vector<int> &vec);
void ausgabe(const vector<int> &vec);

int main()
{
    vector<int> vec1;

    for (int i = 0; i < 100; i++)
    {
        int zufallszahl = generiereZufallszahl(1, 100);
        vec1.push_back(zufallszahl);
    }

    cout << "Ausgabe Vector 1: " << endl;
    ausgabe(vec1);

    //////////////////////////////
    vector<int> vec2(100);

    for (int i = 0; i < 100; i++)
    {
        vec2[i] = generiereZufallszahl(1, 100);
    }

    cout << endl;
    cout << "Ausgabe Vector 2: " << endl;
    ausgabe(vec2);

    vec2.erase(vec2.begin() + 25, vec2.begin() + 50);

    cout << endl;
    cout << "Ausgabe Vector 2 nach Loeschung von Element 26-50: " << endl;
    ausgabe(vec2);

    vec2.insert(vec2.begin() + 50, 25, 0);

    cout << endl;
    cout << "Ausgabe Vector 2 nach Hinzufuegen von 25 Elementen ab Position 50: " << endl;
    ausgabe(vec2);

    
    //////////////////////////////
    vector<int> vec3;

    vec3 = vec1;

    sortierungsBubbleSort(vec3);

    cout << endl;
    cout << "Ausgabe Vector 1: " << endl;
    ausgabe(vec1);

    cout << endl;
    cout << "Ausgabe Vector 3: " << endl;
    ausgabe(vec3);
}

// Generiert eine Zufallszahl zwischen min und max
int generiereZufallszahl(int min, int max)
{
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> i_bereich(min, max);
    return i_bereich(generator);
}

void sortierungsBubbleSort(vector<int>& vec)
{
    for (int halter = 0; halter < vec.size() - 1; halter++)
    {
        for (int lfr = halter + 1; lfr < vec.size(); lfr++)
        {
            if (vec[lfr] < vec[halter])
            {
                int h = vec[lfr];
                vec[lfr] = vec[halter];
                vec[halter] = h;
            }
        }
    }

}

// Gibt jedes Element des vectors aus. 25 Werte pro Zeile
void ausgabe(const vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i += 25)
    {
        for (int k = i; k < i + 25 && k < vec.size(); k++)
        {
            cout << left << setw(5) << vec[k];
        }

        cout << endl;
    }
}