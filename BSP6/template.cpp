#include <iostream>

using std::cout;
using std::endl;

//liefert den größeren Wert
template <typename T>T greater(T a, T b)
{
	return (a>b?a:b);
}

//Besser:
/*template <typename T, typename U>T greater(T a, U b)
{
	return (a<b?a:b);
}*/

void main()
{
	cout<<"Integer 2,3: "<<greater(2,3)<<"\n";
	cout<<"Integer 4,2: "<<greater(2,2)<<"\n";
	cout<<"Float 2.3f, 4.0f: "<<greater(2.3f, 4.0f)<<"\n";
	cout<<"Float 1.0f, 1.0f: "<<greater(1.0f, 1.0f)<<"\n";
	cout<<"Char c,a: "<<greater('c','a')<<"\n";
	cout<<"Char* abc, cda: "<<greater("abc","cda")<<"\n";

	int i=5, j=6, a, b, c, d;
	long k=7;
	//ersten 2 gehen immer
	a=greater<int>(i,j);	
	b=greater(i,j);			//besser wenn man Typ angibt

	//die 2 gehen manchmal!
	c=greater<int>(i,k);
	//d=greater(i,k);		//funktioniert nicht, kann aber bei manchen Compiler gehen!
	cout<<a<<endl<<b<<endl<<c<<endl<<d;
}