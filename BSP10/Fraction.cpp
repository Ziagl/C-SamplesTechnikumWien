#include <iostream>
#include "Fraction.h"

//Klassenvariable initialisieren
int Fraction::objnumber=0;

Fraction::Fraction(void)
{
	objnumber++;				//Klassenvariable erhöhen
	_objnumber = objnumber;		//Nummer des Objekt ins Objekt speichern
	std::cout<<"Konstruktor()"<<"ONr:"<<_objnumber<<"\n";
}

Fraction::~Fraction(void)
{
	std::cout<<"Destruktor()"<<"ONr:"<<_objnumber<<"\n";
}

Fraction::Fraction(int num, int denom)
{
	objnumber++;
	_objnumber = objnumber;
	std::cout<<"Konstruktor("<<num<<","<<denom<<")"<<"ONr:"<<_objnumber<<"\n";
	_numerator = num;
	_denominator = denom;
}

void Fraction::print(std::ostream &os) const
{
	os<<_numerator<<"/"<<_denominator;
}

//const Fraction --> Fraction kann hier nicht geändert werden
//const --> Methode kann die Instanz nicht verändern
//const sind immer alle Methoden, die nichts an der Instanz ändern

//friend <-- damit kann die Klasse im Fraction.h definiert werden, ist immer noch Global und
//man kann auf die Membervariablen zugreifen
Fraction Fraction::operator+ (const Fraction &other) const
{
	int kgv=_denominator;	//kleinstes gemeinsames Vielfaches der Nenner
	while(kgv%other._denominator != 0)
		kgv+=_denominator;
	return Fraction((kgv * other._numerator)/other._denominator + (kgv * _numerator)/_denominator, kgv);
}

Fraction Fraction::operator+ (int num) const
{
	return Fraction(_numerator + num * _denominator, _denominator);
}

Fraction& Fraction::operator+= (const Fraction &other)
{
	//dereferenzieren, da hier nicht die Adresse, sondern ein Wert (Fraction) übergeben werden soll
	*this=*this+other;
	return *this;
}

Fraction& Fraction::operator+= (int num)
{
	*this=*this+num;
	return *this;
}