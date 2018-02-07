#include <iostream>
#include "Punkt.h"
#include "Quadrat.h"
#include "Rechteck.h"
#include "Oval.h"
#include "Kreis.h"

//Vererbung
//virtual
//...
void main()
{
	int i;
	//Sinnvoll, da so zB ein Array mit Typ Punkt für alle Elemente angelegt werden kann!!!!
	Punkt *p = new Punkt(0,0);
	Punkt *r = new Rechteck(0,0,10,5);
	Punkt *k = new Kreis(0,0,5);
	Punkt *o = new Oval(0,0,5);
	Punkt *q = new Quadrat(0,0,6);

	//ohne virutal alle 0, da immer size von der Basisklasse ausgeführt wird
	//wenn virual bei Punkt,Oval und Rechteck gesetzt --> richtig
	std::cout<<"Punkt: "<<p->size()<<std::endl;
	std::cout<<"Rechteck [10,5]: "<<r->size()<<std::endl;
	std::cout<<"Kreis [5]: "<<k->size()<<std::endl;
	std::cout<<"Oval [5]: "<<o->size()<<std::endl;
	std::cout<<"Quadrat [6]: "<<q->size()<<std::endl;

	//sollten deletes in der klasse (deconstruktor) vorkommen muss dieser auch virtual sein!!!!
	delete p;
	delete r;
	delete k;
	delete o;
	delete q;

	std::cin>>i;
}