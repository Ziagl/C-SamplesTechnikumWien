//#include "Character.h"
#include "NPC.h"
#include "Player.h"

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::ofstream;
using std::ios;

void main()
{
	static const int arraysize=3;
	Character* _array[arraysize];

	std::string _str;
	int x,y,race,gender,value,task;
	int eingabe,j=0;

	cout<<"Charaktergenerierung\n";
	do{
		cout<<"\nWas soll erstellt werden? (0...Player, 1...NPC): ";
		cin>>eingabe;

		if(eingabe==0){
			cout<<"\nPlayer erstellen:\n";

			//Generate Player
			cout<<"Geben Sie die Position (x,y), die Rasse (0-2), das Geschlecht (0 oder 1), den Itemnamen und den Itemwert ein:\n";
			cin>>x>>y>>race>>gender>>_str>>value;

			_array[j] = new Player(x,y,race,gender,_str,value);

			int i;
			do{
				cout<<"Geben Sie die Bewegung des Spielers ein (0-2): ";
				cin>>i;
				switch(i)
				{
					case 0: (dynamic_cast<Player*> (_array[j]))->move();break;		//muss gecastet werden, da Charakter die Funktionen nicht kennt!
					case 1: (dynamic_cast<Player*> (_array[j]))->jump();break;
					case 2: (dynamic_cast<Player*> (_array[j]))->die();break;
				}
			}while(i>=0 && i<=2);

			j++;
		}
		if(eingabe==1)
		{
			cout<<"\nNPC erstellen:\n";
			
			//Generiere NPC
			cout<<"Geben Sie die Position (x,y), die Rasse (0-2), das Geschlecht (0 oder 1) und einen Task (0-3) ein:\n";
			cin>>x>>y>>race>>gender>>task;

			_array[j] = new NPC(x,y,race,gender,task);

			j++;
		}
	}while(j<arraysize);

	//Array in das File schreiben
	ofstream oFile("text.txt",ios::app);

	if(oFile.is_open())
	{
		for(j=0;j<arraysize;++j)	//++j schneller als j++!!!!!!
		{
			oFile<<_array[j]->getString();
			oFile<<std::endl;
		}
		oFile.close();
	}
}