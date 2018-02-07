#include <fstream>
#include <iostream>

using std::ifstream;
using std::cout;

//aus einer Datei lesen
void main3()
{
	ifstream iFile("file.txt");
	char c;

	if(iFile.is_open())
	{
		while(iFile>>c)
			cout<<c;
		iFile.close();
	}
}

using std::ofstream;
using std::cin;
using std::ios;

//in eine Datei schreiben
void main2()
{
	//ios::app		-	anf�gen
	//ios::binary	-	bin�rmodus
	//ios::ate		-	an der Position
	//ios::trunc	-	offenes File �berschreiben (default)
	ofstream oFile("file.txt",ios::app);
	char c;

	if(oFile.is_open())
	{
		cin>>c;
		while(c!='$')
		{
			oFile<<c;
			cin>>c;
		}
		oFile.close();
	}
}