#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>

class Fraction
{
public:
	Fraction(void);
	~Fraction(void);

	Fraction(int num, int denom);
	void print(std::ostream &os) const;

	Fraction operator+ (const Fraction &other) const;
	Fraction operator+ (int num) const;
	Fraction& operator+= (const Fraction &other);
	Fraction& operator+= (int num);

	static int objnumber;	//Klassenvariable die die Anzahl der erstellten Objekte dieser Klasse repräsentiert
private:
	int _objnumber;
	int _numerator;
	int _denominator;
};

#endif