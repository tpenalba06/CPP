#pragma once
#include <iostream>

template <typename T>
class Array{

	private:
			T *_tab;
			unsigned int	_n;
    
	public:
			Array<T>();
			Array<T>(unsigned int n);
			Array<T>(Array& other);
			~Array<T>(){
				if(this->_tab)
					delete this->_tab
			};
			Array<T>	&operator=(Array& other);
			T&			operator[](unsigned int element);
			unsigned int			getN()const; 
			unsigned int size();
			class out : public std::exception{
				const char *what()const throw(){
					return ("Out of bounds");
				};
			};
};

template <typename T>
unsigned int	Array<T>::size()
{
	return (_n);
}

template <typename T>
Array<T>::Array() : _tab(NULL), _n(0)
{
    return ;
}
template <typename T>
Array<T>::Array(unsigned int n) : _n(n)
{
    this->_tab = new T[n];
    return ;
}

template <typename T>
Array<T>::Array(Array& other)
{
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(Array& other)
{
	this->_n = other._n;
	if (this->_tab)
		delete [] this->_tab;
	this->_tab = new T[this->_n];
	for (unsigned int i = 0; i < _n; i++)
	{
		if (this->_tab[i])
			this->_tab[i] = 0;
		this->_tab[i] = other._tab[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int element)
{
	if(element > _n)
		throw(out());
	return this->_tab[element];
}

template<class T>
unsigned int	Array<T>::getN(void) const
{
	return (this->_n);
}