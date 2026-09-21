#include <iostream>
#include <cstring>
#include <tuple>

using namespace std;

int main()
{
    pair<string, int> p1("Meier", 80);
    p1.first = "Graf";
    p1.second = 100;

    char str1[] = "Wacker";
    auto p2 = make_pair(str1, 120);

    strcpy_s(str1, p1.first.c_str());
    cout << str1 << endl;

    ////////////////////////////

    tuple<int, const char*, double> t1(5, "Meier", 4.7);
    auto t2 = make_tuple("Wacker", "Willi");
    get<0>(t3) = 15;
    get<1>(t3) = "Lisa";
    get<2>(t3) = 4500.70;

    cout << get<0>(t2) << get<1>(t2) << endl;
    int a;
    double b;
    string c;
    tie(a, c, b) = t1;

}

