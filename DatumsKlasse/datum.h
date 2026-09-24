#pragma once
#include <string>
using namespace std;

#ifndef _KONTO_H_
#define _KONTO_H_

class Datum
{
private:
    string _tag;
    string _monat;
    string _jahr;

public:
    // ---------- Konstruktoren ----------
    Datum();
    Datum(string tag, string monat, string jahr);

    // ---------- Getter ----------
    string getTag() const { return _tag; }
    string getMonat() const { return _monat; }
    string getJahr() const { return _jahr; }
    string toString() const;
    bool isSchaltjahr() const;

    // ---------- Setter ----------
    void setTag(string tag);
    void setMonat(string monat);
    void setJahr(string jahr);


};

#endif