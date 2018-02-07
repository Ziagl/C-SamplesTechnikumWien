#include <iostream>

//alles was verwendet wird kann mit using (namenspace) eingebunden werden
//einzeln besser als gleich ganzen namensraum
//kann auch innerhalb von funktionen gemacht werden, gilt dann aber auch nur für die funktion
using std::cout;
using std::endl;
using std::cin;

//einfaches Eingeben und Ausgeben
int main1()
{
	char c;
	int i;

	cout << "Geben Sie ein Zeichen und Wert ein: ";
	cin >> c >> i;

	cout << "Zeichen: " << c << " Wert: " << i << endl;

	cin >> i;
	return 0;
}

//cin.fail()
//cin.bad()
//cin.good()
//cin.unget()
//cin.isdigit()