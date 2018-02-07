#include <iostream>

using std::cout;
using std::cin;

//Pointer übergeben, mit Stern dereferenzieren
void out (int *a)
{
	(*a)++;
}

//Referenz auf Wert übergeben
void out2 (int &a)
{
	a++;
}

void main()
{
	int a=5;
	out(&a);
	cout<<a<<"\n";
	a++;
	cout<<a<<"\n";
	out2(a);
	cout<<a;

	cin>>a;
}