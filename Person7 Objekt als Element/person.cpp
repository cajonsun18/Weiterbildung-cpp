#include "person.h"
#include <regex>
#include <stdexcept>

// ---------- Konstruktoren ----------
Person::Person()
	: Person("NV", "NV")
{
}

Person::Person(string nachname, string vorname)
	: Person(nachname, vorname, "NV", "NV", "NV", "NV", "NV", "NV")
{
}

Person::Person(string nachname, string vorname,
	string adressart, string strasse,
	string hausnr, string plz,
	string ort, string gebDatum)
{
	setNachname(nachname);
	setVorname(vorname);
	_adresse.setAdressart(adressart);
	_adresse.setStrasse(strasse);
	_adresse.setHausNr(hausnr);
	_adresse.setPlz(plz);
	_adresse.setOrt(ort);
	setGebDatum(gebDatum);
}

/////// ALTERNATIVE MIT ELEMENTINITIALISIERER ////////
/*Person::Person(string nachname, string vorname,
	string adressart, string strasse,
	string hausnr, string plz,
	string ort, string gebDatum)
	: _adresse(Adresse(adressart, strasse, hausnr, plz, ort))	// Man kann die Adresse auch als Elementinitialisierer übergeben
{
	setNachname(nachname);
	setVorname(vorname);
	setGebDatum(gebDatum);
}*/


// ---------- Getter ----------
string Person::getNachname() const
{
	return _nachname;
}

string Person::getVorname() const
{
	return _vorname;
}

string Person::getAdressArt() const
{
	return _adresse.getAdressArt();
}

string Person::getHausNr() const
{
	return _adresse.getHausNr();
}

string Person::getGebDatum() const
{
	return string();
}

Adresse Person::getAdresse() const
{
	return _adresse;
}

string Person::toString() const
{
	return "\n" "PERSON" "\n"
		"Nachname: " + _nachname + "\n"
		+ "Vorname: " + _vorname + "\n"
		+ "Geb. Datum: " + _gebDatum + "\n"
		+ _adresse.toString() + "\n\n";
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

