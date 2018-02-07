#ifndef _MYCONTAINER_H_
#define _MYCONTAINER_H_

#include <string>

using std::string;

//Templateklasse
template <typename T, int N=20>class MyContainer
{
public:
	MyContainer(void){_count = 0;};
	void add(T value);
	T get(int index);
	T getMax();
	int size();
private:
	static const int _max=N;
	int _count;
	T _values[_max];
};

//ausprogrammierte Methoden
template <typename T, int N>void MyContainer<T,N>::add(T value)
{
	if(_count<_max)
	{
		_values[_count]=value;
		_count++;
	}
}

template <typename T, int N>T MyContainer<T,N>::get(int index)
{
	if(index<=_count)
		return _values[index];
	else
		return _values[_count];
}

template <typename T, int N>T MyContainer<T,N>::getMax()
{
	T max=0;
	for(int i=0; i<_count; ++i)
		if(max<_values[i])
			max=_values[i];
	return max;
}

template <typename T, int N>int MyContainer<T,N>::size()
{
	return _count;
}

//Char Spezialisierung
//Funkionen werden neu implementiert
//damit zB Operationen für Zahlen hier nicht mehr zur Verfügung stehen
//getMax wäre hier zB sinnlos
template <int N> class MyContainer<char,N>
{
public:
	MyContainer(void)/*{_values="";}*/;
	void add(char value)/*{_values+=value;}*/;
	char get(int index)/*{return _values[index];}*/;
	string get()/*{return _values;}*/;
	int size()/*{return _values.length();}*/;
private:
	string _values;
};

//ausprogrammierte Methoden
template <int N> MyContainer<char ,N>::MyContainer(void)
{
	_values="";
}

template <int N> void MyContainer<char, N>::add(char value)
{
	_values+=value;
}

template <int N> char MyContainer<char, N>::get(int index)
{
	return _values[index];
}

template <int N> string MyContainer<char, N>::get()
{
	return _values;
}

template <int N>int MyContainer<char, N>::size()
{
	return _values.length();
}

#endif
