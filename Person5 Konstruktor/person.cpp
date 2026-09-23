#include "person.h"
#include <regex>
#include <stdexcept>

// ---------- Konstruktoren ----------
Person::Person()
	: _nachname("Nv"), _vorname("Nv"), _strasse("Nv"), _plz("Nv"), _ort("Nv")
{
}

Person::Person(string nachname, string vorname)
	: Person()
{
	setNachname(nachname);
	setVorname(vorname);
}

Person::Person(string nachname, string vorname,
	string strasse, string plz, string ort)
	: Person(nachname, vorname)
{
	setStrasse(strasse);
	setPlz(plz);
	setOrt(ort);
}


// ---------- Getter ----------
string Person::getNachname() const
{
	return _nachname;
}

string Person::getVorname() const
{
	return _vorname;
}

string Person::getStrasse() const
{
	return _strasse;
}

string Person::getPlz() const
{
	return _plz;
}

string Person::getOrt() const
{
	return _ort;
}

string Person::toString() const
{
	return _nachname + ", " + _vorname + ", " + _strasse + ", " + _plz + ", " + _ort;
}

// ---------- Setter ----------
bool Person::setNachname(string value)
{
	regex muster("^(O')?([A-ZÄÖÜ][a-zäöüß]*)([ -][A-ZÄÖÜ][a-zäöüß]*)?$");

	if (!regex_match(value, muster))
	{
		throw invalid_argument("Fehler bei Nachname: " + value);
	}

	_nachname = value;
	return true;
}

bool Person::setVorname(string value)
{
	regex muster("^(O')?([A-ZÄÖÜ][a-zäöüß]*)([ -][A-ZÄÖÜ][a-zäöüß]*)?$");

	if (!regex_match(value, muster))
	{
		throw invalid_argument("Fehler bei Vorname: " + value);
	}

	_vorname = value;
	return true;
}

bool Person::setStrasse(string value)
{
	regex muster("^[A-Za-zÄÖÜäöüß][A-Za-zÄÖÜäöüß .'-]*[ ][0-9]{1,4}[ ]?[A-Za-z]?([/-][0-9]{1,4}[A-Za-z]?)?$");

	if (!regex_match(value, muster))
	{
		throw invalid_argument("Fehler bei Strasse: " + value);
	}

	_strasse = value;
	return true;
}

bool Person::setPlz(string value)
{
	regex muster("^(0[1-9]|[1-9][0-9])[0-9]{3}$");

	if (!regex_match(value, muster))
	{
		throw invalid_argument("Fehler bei PLZ: " + value);
	}

	_plz = value;
	return true;
}

bool Person::setOrt(string value)
{
	regex muster("^[A-Za-zÄÖÜäöüß][A-Za-zÄÖÜäöüß .'()/-]{0,58}[A-Za-zÄÖÜäöüß.)]$");

	if (!regex_match(value, muster))
	{
		throw invalid_argument("Fehler bei Ort: " + value);
	}

	_ort = value;
	return true;
}

