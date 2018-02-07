#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

void main1()
{
	int x,y,size;
	vector<int> vec;

	//Eingabe
	cout<<"Fibonacci Tasks\n\n";
	cout<<"Erste Zahl: ";
	cin>>x;
	cout<<"Zweite Zahl: ";
	cin>>y;
	cout<<"Anzahl der Elemente: ";
	cin>>size;

	vec.reserve(size);		//hier wird dem Vector eine fixe Größe zugewiesen, es können aber auch mehr eingefügt werden!

	vec.push_back(x);
	vec.push_back(y);

	//Berechnung
	for(int i=2; i<size; ++i)
		vec.push_back(vec[i-2] + vec[i-1]);

	//Ausgabe:
	cout<<"\nElemente aufsteigend (vec1):\n";
	for(vector<int>::iterator it = vec.begin(); it!=vec.end(); ++it)
		cout<<(*it)<<" ";

	cout<<"\nElemente absteigend (vec2):\n";
	vector<int> vec2;
	//alle Elemente in verkehrter Reihenfolge in den 2. Vector speichern --> ReverseIterator oder Assign!
	/*for(vector<int>::reverse_iterator it = vec.rbegin(); it!=vec.rend(); ++it)
		vec2.push_back(*it);*/
	vec2.assign(vec.rbegin(),vec.rend());

	for(vector<int>::iterator it = vec2.begin(); it!=vec2.end(); ++it)
		cout<<(*it)<<" ";

	cout<<"\n\nvec1:\n";
	cout<<"Capacity: "<<vec.capacity()<<"\n";
	cout<<"Size: "<<vec.size()<<"\n";

	cin>>x;
}