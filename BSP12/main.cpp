//Algorithmen

#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::vector;

static const int count=10;
int i=0;					//Zählvariable für Generator

int newInteger();
void printInteger(int i);
void printVector(vector<int> &v);
void printArray(int a[count]);

void main()
{
	vector<int> vec1(10);
	int arr[10];
	
	//mit STL
	cout<<"mit STL Container\n";
	i=0;														//i mit 0 initialisieren
	std::generate(vec1.begin(), vec1.end(), newInteger);		//Vector mit Zahlen füllen
	printVector(vec1);											//Vector ausgeben
	cout<<"\n\n";
	std::reverse(vec1.begin(), vec1.end());						//Reihenfolge der Elemente umdrehen
	//std::remove(vec1.begin(), vec1.end(), 5);					//Element 5 löschen
	//Löscht Element und schiebt ein neues hinein --> immer noch 10 Elemente
	//mit Erase/remove gehts
	vec1.erase(std::remove(vec1.begin(), vec1.end(),5),vec1.end());
	printVector(vec1);
	cout<<"\n\n";

	//ohne STL
	cout<<"ohne STL Container\n";
	i=4;														//i mit 4 initialisiern
	std::generate(arr, arr+count, newInteger);
	printArray(arr);
	cout<<"\n\n";
	std::reverse(arr, arr+count);
	printArray(arr);
	cout<<"\n\n";
}

void printArray(int a[count])
{
	std::for_each(a, a+count, printInteger);
}

//gibt einen Vector Elementweise aus
void printVector(vector<int> &v)
{
	std::for_each(v.begin(), v.end(), printInteger);
}

//Funktion die einen Integer ausgibt
void printInteger(int i)
{
	cout<<i<<" ";
}

//Funktion die einen Integer zurückgibt
int newInteger()
{
	return i++;
}