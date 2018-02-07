#include <iostream>

//geschachtelte Schleifen, die alle Primzahlen bis zu einem bestimmten Wert liefern
void main4()
{
	//Berechnung
	const static int size=120;
	int ar[size]={0};
	int i;
	
	std::cout<<"Primzahlen"<<std::endl;

	for(i=2; i<size; i++)
	{
		if(ar[i]==0)
		{
			for(int j=i*i; j<size; j+=i)
				ar[j]=1;
			//Ausgabe Primzahl
			std::cout<<i<<" ";
		}
	}

	std::cin>>i;
}