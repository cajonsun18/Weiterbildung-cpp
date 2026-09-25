#pragma once
#include <string>
using namespace std;

#ifndef _TIER_H_
#define _TIER_H_

class Tier
{
private:
	string _name;
	string _farbe;
	int _alter;
public:
	// ---------- De-/Konstruktoren ----------
	~Tier() = default;

	Tier(string name, string farbe, int alter);
	Tier(string name, string farbe);
	Tier(string name);
	Tier();

	// ---------- Getter ----------
	string getName() const { return _name; }
	string getFarbe() const { return _farbe; }
	int getAlter() const { return _alter; }
	string toString() const;
	virtual string getFutterart() const = 0;

	// ---------- Setter ----------
	void setName(string value);
	void setFarbe(string value);
	void setAlter(int value);
	virtual void setFutterart(string value) = 0;
};

#endif