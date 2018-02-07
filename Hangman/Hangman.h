#ifndef _HANGMAN_H_
#define _HANGMAN_H_
#include<vector>
#include<string>
#include<bitset>

using std::vector;
using std::string;


class Hangman
{
public:
	Hangman(string file);
	~Hangman(void);

	void printWords();
	void startGame(int l);
private:
	int _lifes;					//Leben
	bool _won;					//Flag f�r den Sieg
	vector<string> _words;		//W�rter aus der Datei
	vector<char> _chars;		//Buchstaben eines Wortes
	vector<char> _charOut;		//die Ausgabe des Wortes (zu Beginn nur _)
	vector<char> _charIn;		//alle bereits eingegebenen Buchstaben

	void readFromFile(string file);
	void writeGUI();
	void printVector(vector<char> &v);
	bool hasElement(char c);	//pr�ft ob das Zeichen im Buchstabenvektor vorhanden ist
	bool tryChar(char c);		//pr�fen ob das Zeichen im gesuchten Vektor vorkommt
	void copyWort(int i);		//kopiert ein Wort Zeichen f�r Zeichen in den chars Vektor
	static char binToAscii(std::bitset<8> set);
};
#endif
