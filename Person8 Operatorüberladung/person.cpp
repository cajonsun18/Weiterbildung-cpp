#include "person.h"
#include <regex>
#include <stdexcept>
#include <ostream>

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
	_adresse = new Adresse();
	_adresse->setAdressart(adressart);
	_adresse->setStrasse(strasse);
	_adresse->setHausNr(hausnr);
	_adresse->setPlz(plz);
	_adresse->setOrt(ort);
	setGebDatum(gebDatum);
}

Person::Person(const Person& person)
{
	setVorname(person.getVorname());
	setNachname(person.getNachname());
	setGebDatum(person.getGebDatum());
	_adresse = new Adresse(*person._adresse);

	////// ALTERNATIV AUCH ELEMENTWEISE //////
	//_adresse = new Adresse(person._adresse->getAdressArt(),
	//	person._adresse->getStrasse(),
	//	person._adresse->getHausNr(),
	//	person._adresse->getPlz(),
	//	person._adresse->getOrt());
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

string Person::getAdressArt() const
{
	return (*_adresse).getAdressArt();
}

string Person::getHausNr() const
{
	return (*_adresse).getHausNr();
}

string Person::getGebDatum() const
{
	return _gebDatum;
}

string Person::toString() const
{
	return "\n" "PERSON" "\n"
		"Nachname: " + _nachname + "\n"
		+ "Vorname: " + _vorname + "\n"
		+ "Geb. Datum: " + _gebDatum + "\n"
		+ (*_adresse).toString() + "\n";
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

Person Person::operator=(const Person& person)
{
	_nachname = person._nachname;
	_vorname = person._vorname;
	_gebDatum = person._gebDatum;
	_adresse = new Adresse(*person._adresse);
	return Person();
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

ostream& operator<<(ostream& COUT, const Person &p)
{
	COUT << p.toString();
	return COUT;
}
