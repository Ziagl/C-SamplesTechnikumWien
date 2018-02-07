#include <iostream>

using std::cout;
using std::cin;

int add(int i, int j)
{
	return i+j;
}

int sub(int i, int j)
{
	return i-j;
}

void main5()
{
	int (*fptr)(int i, int j);
	int i;

	fptr=add;
	cout<<fptr(1,2)<<"\n";
	fptr=sub;
	cout<<fptr(2,1)<<"\n";
	cin>>i;
}