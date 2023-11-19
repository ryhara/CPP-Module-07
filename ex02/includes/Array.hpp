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
		T*					_array;
		unsigned int		_size;
	public:
		Array(): _array(NULL), _size(0) {};
		Array(unsigned int n) : _array(new T[n]()), _size(n) {};
		Array(const Array& copy) : _array(NULL), _size(0) { *this = copy; };
		~Array(){ delete [] _array; };
		Array& operator=(const Array& obj) {
			if (this != &obj)
			{
				delete [] _array;
				this->_size = obj._size;
				try {
					this->_array = new T[_size];
				} catch (std::bad_alloc& e) {
					std::cerr << e.what() << std::endl;
					std::exit(1);
				}
				for (unsigned int i = 0; i < _size; i++)
					this->_array[i] = obj._array[i];
			}
			return (*this);
		}
		T& operator[](unsigned int index) {
			if (index >= _size)
				throw std::out_of_range(RED"Error: Out of range"END);
			return (this->_array[index]);
		};
		const T& operator[](unsigned int index) const {
			if (index >= _size)
				throw std::out_of_range(RED"Error: Out of range"END);
			return (this->_array[index]);
		};
		int size() const { return (this->_size); };

};

#endif