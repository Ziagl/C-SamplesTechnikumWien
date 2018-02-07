#include <iostream>
#include <list>
#include <string>

typedef std::list<int> intList;

int irand(int a, int b)
{
	double r = b - a + 1;
	return a + static_cast<int>(r*rand()/(RAND_MAX+1.0));
}

void printList(intList l)
{
	//ist Liste leer?
	if(l.empty())
	{
		std::cout<<"empty";
	}
	else
	{
		for(std::list<int>::iterator it=l.begin(); it!=l.end(); ++it)
			std::cout<<(*it)<<" ";
	}
	std::cout<<"\n\n";
	
}

bool evenNumber(int x)
{
	return !(x%2);
}

//2 listen mit 20 elementen 0-100 und ausgeben
void main()
{
	intList list1;
	intList list2;
	static const int size=20;
	int i;

	for(int i=0; i<size; ++i)
	{
		list1.push_back(irand(0,100));
		list2.push_back(irand(0,100));
	}

	//aufsteigend sortieren
	list1.sort();
	list2.sort();

	//Listen ausgeben
	printList(list1);
	printList(list2);

	std::cout<<"Gerade Zahlen aus erster Liste loeschen\n";
	//alle geraden Zahlen herauslöschen
	list1.remove_if(evenNumber);
	printList(list1);

	std::cout<<"erste Liste in 2. einfuegen\n";
	std::list<int>::iterator it = list2.begin();
	while((*it)<(*list1.begin()))it++;
	list2.splice(it,list1);
	printList(list1);
	printList(list2);

	//doppelte Elemente löschen
	std::cout<<"doppelte Elemente loeschen\n";
	list2.unique();
	printList(list2);

	std::cin>>i;
}