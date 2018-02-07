#include <iostream>
#include <vector>

using std::vector;
using std::cout;

void printVector(vector<int> &v, const char* str)
{
	cout<<str<<"\n";
	for(vector<int>::iterator it=v.begin();it!=v.end();++it)
		cout<<(*it)<<" ";
	cout<<"\n";
}

//Vector 1 die 2. Hälfte des 2. Vectors übergeben
//schnellste Möglichkeit
void main()
{
	vector<int> vec1;
	vector<int> vec2;

	for(int i=1; i<=10; ++i)
	{
		vec2.push_back(i);
	}

	//letzte Hälfte des Vectors zuweisen
	vec1.assign(vec2.begin()+vec2.size()/2,vec2.end());

	printVector(vec1,"Vec1:");
	printVector(vec2,"Vec2:");
}