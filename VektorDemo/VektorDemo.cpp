#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec1(100);
    vector<int> vec2;

    vec1.push_back(45);
    vec2.push_back(45);
    
    for (int i = 100; i < 120; i++)
    {
        vec1.push_back(i);
        vec2.push_back(i);
    }

    for (int i = 0; i < 10; i++)
    {
        vec1[i] = i * i;
    }

    vec1.insert(vec1.begin() + 5, 329);     // An Position 5 wird ein Element mit dem Wert 329 eingefügt. Alle folgenden Elemente wandern ein Element weiter. Also Element 5 wird zu Element 6 usw.
    vec1.erase(vec1.begin() + 3);           // Löscht das 3.Element. Size wird um 1 reduziert
    vec1.erase(vec1.end() - 50, vec1.end()); // Löscht die letzten 50 Elemente. Size wird um 50 reduziert
    vec1.shrink_to_fit();                   // Passt die Capacity auf die Size an. Also die Elemente, die einen Wert zugewiesen bekommen haben
    vec1.resize(5);                         // Die Size wird auf 5 geändert. Heißt alle nachfolgenden Elemente werden gelöscht. Capacity bleibt aber weiterhin höher
    vec1.reserve(1000);                     // Es werden 1000 Elemente vorgemerkt. Heißt die Size ist weiterhin kleiner aber die Capacity ist jetzt 1000
    vec1.clear();                           // Der Inhalt des Vectors wird gelöscht. Size wird 0, Capacity bleibt weiterhin bei 1000

}