#include "person.h"
#include <regex>
#include <stdexcept>

// ---------- Konstruktoren ----------
Person::Person()
	: Person("NV", "NV")
{
}

Person::Person(string nachname, string vorname)
	: Person(nachname, vorname, "NV", "NV", "NV", "NV")
{	
}

Person::Person(string nachname, string vorname,
	string strasse, string plz, string ort, string gebDatum)
{
	setNachname(nachname);
	setVorname(vorname);
	setStrasse(strasse);
	setPlz(plz);
	setOrt(ort);
	setGebDatum(gebDatum);
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

string Person::getGebDatum() const
{
	return string();
}

string Person::toString() const
{
	return "\n" "PERSON" "\n"
		"Nachname: " + _nachname + "\n"
		+ "Vorname: " + _vorname + "\n"
		+ "Strasse: " + _strasse + "\n"
		+ "Plz: " + _plz + "\n"
		+ "Ort: " + _ort + "\n"
		+ "Geb. Datum: " + _gebDatum + "\n\n";
}

// ---------- Setter ----------
void Person::setNachname(string value)
{
	regex muster("([A-ZÄÖÜ][a-zäöüß]*)([ |-][A-ZÄÖÜ][a-zäöüß]*)?");
	if (value == "NV" || regex_match(value, muster))
	{
		_nachname = value;
	}
	else
	{
		throw invalid_argument("Falsche Eingabe bei dem Nachnamen");
	}
}

void Person::setVorname(string value)
{
	regex muster("[A-ZÄÖÜ][a-zäöüß]*([ |-][A-ZÄÖÜ][a-zäöüß]*)?");
	if (value == "NV" || regex_match(value, muster))
	{
		_vorname = value;
	}
	else
	{
		throw invalid_argument("Falsche Eingabe bei dem Vornamen");
	}
}

void Person::setStrasse(string value)
{
	regex muster("^[A-Za-zÄÖÜäöüß][A-Za-zÄÖÜäöüß .'-]*[ ][0-9]{1,4}[ ]?[A-Za-z]?([/-][0-9]{1,4}[A-Za-z]?)?$");

	if (value == "NV" || regex_match(value, muster))
	{
		_strasse = value;
	}
	else
	{
		throw invalid_argument("Fehler bei Strasse: " + value);
	}

}

void Person::setPlz(string value)
{
	regex muster("^(0[1-9]|[1-9][0-9])[0-9]{3}$");

	if (value == "NV" || regex_match(value, muster))
	{
		_plz = value;
	}
	else
	{
		throw invalid_argument("Fehler bei PLZ: " + value);
	}
}

void Person::setOrt(string value)
{
	regex muster("^[A-Za-zÄÖÜäöüß][A-Za-zÄÖÜäöüß .'()/-]{0,58}[A-Za-zÄÖÜäöüß.)]$");

	if (value == "NV" || regex_match(value, muster))
	{
		_ort = value;
	}
	else
	{
		throw invalid_argument("Fehler bei Ort: " + value);
	}
}

void Person::setGebDatum(string value)
{
	regex muster("^[0-9]{2}[.][0-9]{2}[.][0-9]{4}$");

	if (value == "NV" || regex_match(value, muster))
	{
		_gebDatum = value;
	}
	else
	{
		throw invalid_argument("Fehler bei Datum: " + value);
	}
}

