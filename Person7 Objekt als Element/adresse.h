#pragma once
#include <string>
using namespace std;

#ifndef _ADRESSE_H_
#define _ADRESSE_H_


class Adresse
{
private:
	string _adressart;
	string _strasse;
	string _hausnr;
	string _plz;
	string _ort;

public:
	// ---------- Konstruktoren ----------
	Adresse(string adressart, string strasse, string hausnr,
		string plz, string ort);
	Adresse();
	
	~Adresse() = default;

	// ---------- Getter ----------
	string getAdressArt() const { return _adressart; }
	string getStrasse() const { return _strasse; }
	string getHausNr() const { return _hausnr; }
	string getPlz() const { return _plz; }
	string getOrt() const { return _ort; }

	string toString() const;

	// ---------- Setter ----------
	void setAdressart(string value);
	void setStrasse(string value);
	void setHausNr(string value);
	void setPlz(string value);
	void setOrt(string value);
};

#endif