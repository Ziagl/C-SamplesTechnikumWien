#ifndef _MYCONTAINER_H_
#define _MYCONTAINER_H_

//Templateklasse
//Ein Container der generisch Werte abspeichert, hat aber eine fixe maximale Größe!
//Die Größe kann als Wert übergeben werden --> höhere Geschwindigkeit beim anlegen
//Kann auch als Defaultwert angegeben werden, so muss man es nicht extra übergeben
template <typename T, int N=20>class MyContainer
{
public:
	MyContainer(void){_count = 0;};
	void add(T value);			//hinzufügen eines neuen Elements
	T get(int index);			//ein bestimmtes Element (index) holen
	T getMax();					//das größte Element holen
	int size();					//die Anzahl der Elemente im Array
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

#endif
