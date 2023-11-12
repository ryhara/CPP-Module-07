#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

#define END				"\033[0m"
#define BOLD			"\033[1m"
#define BLACK			"\033[30m"
#define RED				"\033[31m"
#define GREEN			"\033[32m"
#define YELLOW			"\033[33m"
#define BLUE			"\033[34m"
#define MAGENTA			"\033[35m"
#define CYAN			"\033[36m"
#define WHITE			"\033[37m"
#define UNDERLINE		"\033[4m"
#define BOLD_UNDERLINE	"\033[1;4m"

template <typename T>
class Array
{
	private:
		T*		_array;
		int		_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array();
		Array& operator=(const Array& obj);
		T& operator[](int index);
		const T& operator[](int index) const;
		int size() const;
		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array& copy)
{
	*this = copy;
}

template <typename T>
Array<T>::~Array()
{
	if (_array)
		delete [] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	if (this == &obj)
		return *this;
	this->_size = obj._size;
	this->_array = new T[_size];
	for (int i = 0; i < _size; i++)
		this->_array[i] = obj._array[i];
	return (*this);
}

template <typename T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || index >= _size)
		throw OutOfRangeException();
	return (this->_array[index]);
}

template <typename T>
const T& Array<T>::operator[](int index) const
{
	if (index < 0 || index >= _size)
		throw OutOfRangeException();
	return (this->_array[index]);
}

template <typename T>
int Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
const char* Array<T>::OutOfRangeException::what() const throw()
{
	return (RED"Error: Out of range"END);
}

#endif