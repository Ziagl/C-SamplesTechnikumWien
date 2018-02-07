#include <iostream>
#include "Fraction.h"

using std::cout;
using std::ostream;

//Globale überschriebene Operatorfunktion
//Damit kann man Fraction mit cout<<Fraction ausgeben
//wenn << in Fraction definiert würde, kann man nur f<<cout Fraction ausgeben
ostream& operator<<(ostream &os, Fraction &f);

void main()
{
	//Zwei Brüche addieren
	Fraction f(7,9);
	Fraction g(1,13);

	Fraction r=f+g;
	cout<<f<<"+"<<g<<"="<<r<<"\n";

	//Ganzzahl zum Bruch addieren
	Fraction f1(1,2);
	Fraction r2=f1+r+1;

	cout<<f1<<"+1+"<<r<<"="<<r2<<"\n";

	//+=
	Fraction f2(1,2);
	cout<<f2<<"+=1 ";
	f2+=1;
	cout<<f2<<"\n";

	cout<<"\n*************************\n\n";
	Fraction a(1,2), b(2,5), c(2,3);
	c+=a+b+1;
	c+=c+Fraction(1,3);
	cout<<"a:"<<a<<" b:"<<b<<" c:"<<c<<"\n";

	cout<<"\n*************************\n\n";
	Fraction* x = new Fraction(1,2);
	Fraction* y = new Fraction(3,8);
	*x = *y + 4;
	cout<<*x<<"\n";
	delete(x);
	delete(y);
}

ostream& operator<< (ostream &os, Fraction &f)
{
	f.print(os);
	return os;
}