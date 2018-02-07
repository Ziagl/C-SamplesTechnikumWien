#include <iostream>
#include <fstream>
#include <string>
#include <map>		//für mulitmap

using std::cout;
using std::cin;
using std::multimap;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

typedef multimap<string, string> smap;

//Studenten aus dem File in den Container laden
void readStudents(smap &m, const char* file)
{
	ifstream iFile(file);

	if(iFile.is_open())
	{
		string str,key;
		while(!iFile.eof())
		{
			iFile>>key>>str;		//>> liest immer bis zum Zeilenende bzw. ersten Leerzeichen
			m.insert(std::pair<string, string>(key,str));
		}
	}
	else
		cout<<"Error: File does not exist!";

	iFile.close();
}

//Studenten aus dem Container in ein File speichern
void storeStudents(smap &m, const char* file)
{
	ofstream oFile(file,ios::trunc);

	if(oFile.is_open())
		for(smap::iterator it=m.begin();it!=m.end();++it)
			oFile<<it->first<<" "<<it->second<<"\n";

	oFile.close();
}

//Einen Container ausgeben
void printMap(smap &m, const char* str, bool reverse=false)
{
	cout<<"Print Map "<<str<<"\n\n";

	if(reverse)
		for(smap::reverse_iterator it=m.rbegin();it!=m.rend();++it)
			cout<<it->first<<"\n";
	else
		for(smap::iterator it=m.begin();it!=m.end();++it)
			cout<<it->first<<"\n";

	cout<<"\n";
}

void main0()
{
	smap students;

	readStudents(students,"students3rdterm.txt");
	printMap(students, "3rd term:");

	readStudents(students, "students1stterm.txt");
	printMap(students, "1st term and 3rd term: (reverse order)",true);

	//ersetzen (Hubert hat noch keine email Adresse!
	smap::iterator it = students.find("Hubert");
	it->second = "gs09m021@technikum-wien.at";

	storeStudents(students,"studentsMGS.txt");
}
