#include <iostream>

#include "MyContainer.h"

using std::cout;

void  main()
{
	//Container mit größe 10
	MyContainer<int,10> m;

	//Container mit Defaultgröße (20) sie Definition!
	//MyContainer<int> m

	m.add(1);
	m.add(3);
	m.add(5);
	m.add(9);
	m.add(2);
	m.add(48);
	m.add(43);

	cout<<"Values:\n";
	for(int i=0; i<m.size(); ++i)
		cout<<m.get(i)<<" ";

	cout<<"\n3. Value: ";
	cout<<m.get(2)<<"\n";

	cout<<"Max Value: ";
	cout<<m.getMax()<<"\n";
}