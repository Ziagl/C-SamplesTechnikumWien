#ifndef _MYVEKTOR_H_
#define _MYVEKTOR_H_

#include <math.h>
#include <iostream>

using std::cout;

template <typename T, int DIM=3>class MyVektor
{
public:
	MyVektor(void);
	~MyVektor(void);

	void add(T value);

	MyVektor operator+ (MyVektor &other) const;		//Addieren
	MyVektor operator- (MyVektor &other) const;		//Subtrahieren
	MyVektor operator* (T value) const;				//Skalarmulitplikation
	MyVektor operator/ (T value) const;				//Skalardivision
	MyVektor operator* (MyVektor &other) const;		//Innere Produkt
	MyVektor operator^ (MyVektor &other) const;		//Kreuzprodukt
	double magnitude() const;						//Länge des Vektors
	double magnitude_pow() const;					//Quadrat der Länge des Vektors
	MyVektor normalize() const;						//normalisierter Vektor

	void print(std::ostream& os);
	int getSize() const;							//liefert die Dimension des Vektors

protected:
	static const int _dimension=DIM;
	int _size;
	T _values[DIM];
};

template <typename T, int DIM>MyVektor<T,DIM>::MyVektor(void)
{
	_size=0;
}

template <typename T, int DIM>MyVektor<T,DIM>::~MyVektor(void)
{
}

//Werte hinzufügen
template <typename T, int DIM>void MyVektor<T,DIM>::add(T value)
{
	if(_size<_dimension)
	{
		_values[_size] = value;
		_size++;
	}
	else
		throw "Zu viele Argumente!";
}

//Addition
template <typename T, int DIM>MyVektor<T,DIM> MyVektor<T,DIM>::operator+ (MyVektor &other) const
{
	if(_size!=other.getSize())
		throw "Vektoren haben unterschiedliche Dimensionen!";
	else
	{
		MyVektor out;
		for(int i=0; i<_size; ++i)
			out.add(_values[i]+other._values[i]);
		return out;
	}
}

//Subtraktion
template <typename T, int DIM>MyVektor<T,DIM> MyVektor<T,DIM>::operator- (MyVektor &other) const
{
	if(_size!=other.getSize())
		throw "Vektoren haben unterschiedliche Dimensionen!";
	else
	{
		MyVektor out;
		for(int i=0; i<_size; ++i)
			out.add(_values[i]-other._values[i]);
		return out;
	}
}

//Skalarmultiplikation
template <typename T, int DIM>MyVektor<T,DIM> MyVektor<T,DIM>::operator* (T value) const
{
	MyVektor out;
	for(int i=0; i<_size; ++i)
		out.add(_values[i]*value);
	return out;
}

//Skalardivision
template <typename T, int DIM>MyVektor<T,DIM> MyVektor<T,DIM>::operator/ (T value) const
{
	MyVektor out;
	if(value!=0)
	{
		for(int i=0; i<_size; ++i)
			out.add(_values[i]/value);
		return out;
	}
	else
		throw "Division durch 0!";
}

//Punktprodukt
template <typename T, int DIM>MyVektor<T,DIM> MyVektor<T,DIM>::operator* (MyVektor &other) const
{
	if(_size!=other.getSize())
		throw "Vektoren haben unterschiedliche Dimensionen!";
	else
	{
		MyVektor out;
		for(int i=0; i<_size; ++i)
			out.add(_values[i]*other._values[i]);
		return out;
	}
}

//Kreuzprodukt
template <typename T, int DIM>MyVektor<T,DIM> MyVektor<T,DIM>::operator^ (MyVektor &other) const
{
	if(_size!=other.getSize())
		throw "Vektoren haben unterschiedliche Dimensionen!";
	else
	{
		MyVektor out;
		if(_size==3)
		{
			out.add(_values[1]*other._values[2] + _values[2]*other._values[1]);
			out.add(_values[2]*other._values[0] + _values[0]*other._values[2]);
			out.add(_values[0]*other._values[1] + _values[1]*other._values[0]);

			return out;
		}
		else
			throw "Kreuzprodukt nur mit 3 dimensionalen Vektoren!";
	}
}

//Magnitude
template <typename T, int DIM>double MyVektor<T,DIM>::magnitude() const
{
	return sqrt(magnitude_pow());
}

//Magnitude_pow
template <typename T, int DIM>double MyVektor<T,DIM>::magnitude_pow() const
{
	double t=0;
	for(int i=0; i<_size; ++i)
		t+=pow(static_cast<double>(_values[i]),2);
	return t;
}

//normalisierter Vektor
template <typename T, int DIM>MyVektor<T,DIM> MyVektor<T,DIM>::normalize() const
{
	double t=0;
	for(int i=0; i<_size; ++i)
		t+=pow(static_cast<double>(_values[i]),2);
	if(t!=0)
		return *this / sqrt(t);
	else
		throw "Division durch 0!";
}

template <typename T, int DIM>void MyVektor<T, DIM>::print(std::ostream &os)
{
	os<<"[";
	for(int i=0; i<_size; ++i)
	{
		if(i!=0)
			os<<",";
		os<<_values[i];
	}
	os<<"]";
}

template <typename T, int DIM>int MyVektor<T, DIM>::getSize() const
{
	return _size;
}

#endif