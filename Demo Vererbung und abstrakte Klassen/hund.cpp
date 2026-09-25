#include "hund.h"

Hund::Hund(string name, string farbe, int alter, string rasse)
{
    setName(name);
    setFarbe(farbe);
    setAlter(alter);
    setRasse(rasse);
}

Hund::Hund(string name, string farbe, int alter)
    : Hund(name, farbe, alter, "NV") // :Tier(name, farbe, alter), _rasse("NV")
{
}

Hund::Hund(string name, string farbe)
    : Hund(name, farbe, 1) // :Tier(name, farbe), _rasse("NV")
{
}

Hund::Hund(string name) // :Tier(name), _rasse("NV")
    : Hund(name, "NV")
{
}

Hund::Hund()
    : Hund("NV")
{
}

string Hund::gibLaut()
{
    return "Wau, wau";
}

string Hund::toString() const 
{
    return Tier::toString()
        + "Rasse: " + _rasse + "\n";
}

string Hund::getFutterart() const
{
    return _futterArt;
}

void Hund::setRasse(string value)
{
    _rasse = value;
}

void Hund::setFutterart(string value)
{
    _futterArt = value;
}
