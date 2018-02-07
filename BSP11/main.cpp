#include <iostream>
#include <string>
#include "MyVektor.h"

using std::string;
using std::ostream;

ostream& operator<<(ostream &os, MyVektor<double, 3> &f);
ostream& operator<<(ostream &os, MyVektor<int, 5> &f);
void printVektor(MyVektor<double, 3> v1, MyVektor<double, 3> v2,MyVektor<double, 3> v3,string str);
void printVektor(MyVektor<double, 3> v1, MyVektor<double, 3> v2,string str);

void main()
{
	MyVektor<double, 3> vec1,vec2,vec3,vec4;
	double r;

	try
	{
		vec1.add(1);
		vec1.add(2);
		vec1.add(3);
		vec1.add(4);
	}catch(char* str)
	{
		cout<<"Exception: "<<str<<"\n\n";
	}

	vec2.add(3);
	vec2.add(2);
	vec2.add(1);

	vec4.add(2);
	vec4.add(8);
	vec4.add(10);

	//Addition
	vec3 = vec1 + vec2;
	printVektor(vec1,vec2,vec3," + ");

	//Subtraktion
	vec3 = vec1 - vec2;
	printVektor(vec1,vec2,vec3," - ");

	//Skalarmultiplikation
	vec3 = vec1*5;
	printVektor(vec1,vec3," * 5 ");

	try{
		//Skalardivision
		vec3 = vec4/0;
		printVektor(vec4,vec3," / 0 ");
	}catch(char* str)
	{
		cout<<"Exception: "<<str<<"\n\n";
	}

	//Punktprodukt
	vec3 = vec1 * vec2;
	printVektor(vec1,vec2,vec3," * ");

	//Kreuzprodukt
	vec3 = vec1 ^ vec2;
	printVektor(vec1,vec2,vec3," x ");

	//Magnitude
	r = vec1.magnitude();
	cout<<"Magnitude von "<<vec1<<" = "<<r<<"\n\n";

	//Magnitude_pow
	r = vec1.magnitude_pow();
	cout<<"Magnitude_pow von "<<vec1<<" = "<<r<<"\n\n";

	//normalisierter Vektor
	vec3 = vec1.normalize();
	cout<<"Normalisierter Vektor "<<vec1<<" = "<<vec3<<"\n\n";

	//Beweis: Normalisierter Vektor hat Länge 1
	r = vec3.magnitude();
	cout<<"Magnitude von normalisierten Vektor "<<vec3<<" = "<<r<<"\n\n";

	//Beispiel mit 5 Dimensinalem Vektor
	MyVektor<int, 5> vec5,vec6,vec7;

	vec5.add(8);vec5.add(2);vec5.add(4);vec5.add(7);
	vec6.add(4);vec6.add(20);vec6.add(2);vec6.add(5);vec6.add(3);

	//vec7 = vec5 * vec6;
	try
	{
		vec7 = vec5 * vec6;
		cout<<vec5<<" * "<<vec6<<" = "<<vec7<<"\n\n";
	}catch(char* str)
	{
		cout<<"Exception: "<<str<<"\n\n";
	}
}

void printVektor(MyVektor<double, 3> v1, MyVektor<double, 3> v2,MyVektor<double, 3> v3, string str)
{
	cout<<v1<<str<<v2<<" = "<<v3<<"\n\n";
}

void printVektor(MyVektor<double, 3> v1, MyVektor<double, 3> v2, string str)
{
	cout<<v1<<str<<" = "<<v2<<"\n\n";
}

ostream& operator<<(ostream &os, MyVektor<double, 3> &f)
{
	f.print(os);
	return os;
}

ostream& operator<<(ostream &os, MyVektor<int, 5> &f)
{
	f.print(os);
	return os;
}