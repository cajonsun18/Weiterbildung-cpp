#include "assistenzhund.h"

Assistenzhund::Assistenzhund(string name, string farbe, int alter, string rasse, string spezialisierung)
    : Hund(name, farbe, alter, rasse), _spezialisierung(spezialisierung)
{
}

Assistenzhund::Assistenzhund(string name, string farbe, int alter, string rasse)
    : Hund(name, farbe, alter, rasse), _spezialisierung("NV")
{
}

Assistenzhund::Assistenzhund(string name, string farbe, int alter)
    : Hund(name, farbe, alter), _spezialisierung("NV")
{
}

Assistenzhund::Assistenzhund(string name, string farbe)
    : Hund(name, farbe), _spezialisierung("NV")
{
}

Assistenzhund::Assistenzhund(string name)
    : Hund(name), _spezialisierung("NV")
{
}

Assistenzhund::Assistenzhund() 
    : Hund(), _spezialisierung("NV")
{
}

string Assistenzhund::toString() const
{
    return Hund::toString() 
        + "Spezialisierung: " + _spezialisierung + "\n";
}

void Assistenzhund::setSpezialisierung(const string &value)
{
    _spezialisierung = value;
}
