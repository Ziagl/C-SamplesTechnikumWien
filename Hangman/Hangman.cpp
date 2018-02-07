#include "Hangman.h"
#include<fstream>
#include<iostream>
#include<time.h>
#include<ctype.h>
#include<algorithm>

using std::ifstream;
using std::cout;
using std::cin;
using std::ios;

Hangman::Hangman(string str)
{
	readFromFile(str);
}

Hangman::~Hangman(void)
{
}

void Hangman::startGame(int l)
{
	//Variablen setzen
	_lifes = l;
	_won = false;
	//Zufallswort suchen
	srand((unsigned)time(NULL));
	int wort = rand()%_words.size();
	copyWort(wort);
	//Spielschleife
	while(_won!=true)
	{
		//solang Buchstabe noch nicht getippt
		char ein;
		do{
			writeGUI();
			cin>>ein;
		}while(hasElement(toupper(ein)));
		//Element in Buchstabenvektor hinzufügen
		_charIn.push_back(toupper(ein));
		//Mit dem gesuchten Wort prüfen
		if(tryChar(ein)==false)
		{
			//wenn der Buchstabe nicht gefunden wird --> ein Leben weniger bzw. Spielabbruch bei 0 Leben
			_lifes--;
			if(_lifes==0)
				break;
		}
	}
	//Ausgabe des Resultats
	system("cls");
	if(_won)
		cout<<"Sie haben gewonnen!\n\nDas gesuchte Wort lautete: ";
	else
		cout<<"Sie haben verloren!\n\nDas gesuchte Wort lautete: ";
	printVector(_chars);
	cin>>_lifes;
}

//Kopiert das gesuchte Wort in einen 2. Vektor, Zeichenweise
void Hangman::copyWort(int i)
{
	const char *chr = _words[i].c_str();
	_chars.clear();
	for(unsigned int j=0; j<strlen(chr);++j)
	{
		_chars.push_back(toupper(chr[j]));
		if(chr[j]==' ')
			_charOut.push_back(' ');
		else
			_charOut.push_back('_');
	}
}

//Findet man den gesuchten Buchstaben im Wort
bool Hangman::tryChar(char c)
{
	int i=0;
	bool flag=false;
	bool won=true;
	for(vector<char>::iterator it=_chars.begin(); it!=_chars.end(); ++it,++i)
	{
		if(*it==toupper(c))
		{
			_charOut[i] = toupper(c);
			flag=true;
		}
		if(_charOut[i]=='_')
			won=false;
	}
	_won=won;
	return flag;
}

//Prüft ob der Buchstabe bereits eingegeben wurde
bool Hangman::hasElement(char c)
{
	for(vector<char>::iterator it=_charIn.begin();it!=_charIn.end();++it)
		if(*it==c) return true;
	return false;
}

//GUI des Spiels
void Hangman::writeGUI()
{
	system("cls");
	cout<<"Hangman:\n";
	cout<<"verbleibende Leben: "<<_lifes<<"\n";
	cout<<"eingegeben Buchstaben: ";
	printVector(_charIn);
	cout<<"\n\n";
	printVector(_charOut);
	cout<<"\n\n--> ";
}

//Funktion gibt einen Vektor Elementweise aus
void Hangman::printVector(vector<char> &v)
{
	for(vector<char>::iterator it=v.begin();it!=v.end();++it)
		cout<<*it<<" ";
}

char Hangman::binToAscii(std::bitset<8> set)
{
	return (char) set.to_ulong();
}

//Liest ein File mit den Wörtern ein
void Hangman::readFromFile(string file)
{
	ifstream iFile(file.c_str(),ios::binary);
	string converted, word;

	_words.clear();

	if(iFile.is_open())
	{
		std::transform(std::istream_iterator<std::bitset<8>>(iFile),
			std::istream_iterator<std::bitset<8>>(),
			std::back_inserter(converted),
			&Hangman::binToAscii);

		string::iterator act_start = converted.begin();
		string::iterator act_end = converted.begin();

		for(;act_end!=converted.end();++act_end)
			if((*act_end)=='\n')
			{
				word.assign(act_start, act_end);
				_words.push_back(word);
				act_start = act_end+1;
			}
		iFile.close();
	}
}

//Gibt den Vektor mit den Wörtern aus
void Hangman::printWords()
{
	for(vector<string>::iterator it=_words.begin(); it!=_words.end();++it)
		cout<<*it<<"\n";
}