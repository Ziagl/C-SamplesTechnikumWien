#include <iostream>
#include "func.h"

using std::cout;

//aufrufen des Funktors, der immer neue Zufallszahlen zurückgibt
void main()
{
	func f(0,100);

	cout<<"Wert1: "<<f()<<"\n";
	cout<<"Wert2: "<<f()<<"\n";
	cout<<"Wert3: "<<f()<<"\n";
}