#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

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
void	iter(T *array, size_t length, void (*f)(T const &))
{
	if (length <= 0 || !array || !f)
		return ;
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

#endif