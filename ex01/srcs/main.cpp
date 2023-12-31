#include "iter.hpp"

template <typename T>
void put_blue(T const &i)
{
	std::cout << BLUE << i << " " << END;
}

template <typename T>
void put_red(T const &i)
{
	std::cout << RED << i << " " << END;
}

template <typename T>
void increment(T &i)
{
	i++;
}


int main(void)
{
	std::cout << "----- const tests -----" << std::endl;
	{
		std::cout << "--- int tests ---" << std::endl;
		const int a[] = {1, 2, 3, 4, 5};
		::iter(a, 5, put_blue);
		std::cout << std::endl;
		::iter(a, 5, put_red);
		std::cout << std::endl;
		std::cout << "------------------" << std::endl << std::endl;
	}

	{
		std::cout << "----- string tests -----" << std::endl;
		const std::string a[] = {"one", "two", "three", "four", "five"};
		::iter(a, 5, put_blue);
		std::cout << std::endl;
		::iter(a, 5, put_red);
		std::cout << std::endl;
		std::cout << "------------------------" << std::endl << std::endl;
	}
	{
		std::cout << "----- char tests -----" << std::endl;
		const char a[] = {'a', 'b', 'c', 'd', 'e'};
		::iter(a, 5, put_blue);
		std::cout << std::endl;
		::iter(a, 5, put_red);
		std::cout << std::endl;
		std::cout << "----------------------" << std::endl << std::endl;
	}
	{
		std::cout << "----- double tests -----" << std::endl;
		const double a[] = {1.1, 2.2, 3.3, 4.4, 5.5};
		::iter(a, 5, put_blue);
		std::cout << std::endl;
		::iter(a, 5, put_red);
		std::cout << std::endl;
		std::cout << "------------------------" << std::endl << std::endl;
	}

	std::cout << "----- not const tests -----" << std::endl;
	{
		std::cout << "--- int tests ---" << std::endl;
		int a[] = {1, 2, 3, 4, 5};
		::iter(a, 5, put_blue);
		::iter(a, 5, increment);
		std::cout << std::endl;
		::iter(a, 5, put_red);
		std::cout << std::endl;
		std::cout << "------------------" << std::endl << std::endl;
	}
	{
		std::cout << "----- char tests -----" << std::endl;
		char a[] = {'a', 'b', 'c', 'd', 'e'};
		::iter(a, 5, put_blue);
		::iter(a, 5, increment);
		std::cout << std::endl;
		::iter(a, 5, put_red);
		std::cout << std::endl;
		std::cout << "----------------------" << std::endl << std::endl;
	}
	{
		std::cout << "----- double tests -----" << std::endl;
		double a[] = {1.1, 2.2, 3.3, 4.4, 5.5};
		::iter(a, 5, put_blue);
		::iter(a, 5, increment);
		std::cout << std::endl;
		::iter(a, 5, put_red);
		std::cout << std::endl;
		std::cout << "------------------------" << std::endl << std::endl;
	}
	return 0;
}