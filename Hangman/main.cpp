#include "Hangman.h"

void main()
{
	Hangman h("hangman.txt");

	//h.printWords();

	h.startGame(10);
}