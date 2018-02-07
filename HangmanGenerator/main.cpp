#include<iostream>
#include<algorithm>
#include<bitset>
#include<fstream>
#include<string>

using std::string;
using std::ofstream;
using std::ios;
using std::cin;
using std::cout;

void main()
{
	ofstream oFile("hangman.txt",ios::app | ios::binary);
	string str;

	cout<<"Hangman Generator:\n\n";
	cout<<"Geben Sie hier bitte Woerter ein:\n\n";

	if(oFile.is_open())
	{
		getline(cin,str);
		while(str.length()!=0)
		{
			str+="\n";
			//String binär in die Datei schreiben
			std::copy(str.begin(), str.end(), std::ostream_iterator<std::bitset<8>>(oFile,""));
			getline(cin,str);
		}
		oFile.close();
	}
}