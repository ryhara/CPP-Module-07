#include "whatever.hpp"
#include <iostream>
#include <string>

int main(void)
{
	{
		std::cout << "--- subject tests ---" << std::endl;
		int a = 2;
		int b = 3;
		std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "after  swap: a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::cout << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "before swap: c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "after  swap: c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		std::cout << "---------------------" << std::endl << std::endl;
	}

	{
		std::cout << "----- my tests -----" << std::endl;
		double a = 2.2;
		double b = 3.3;
		std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "after  swap: a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::cout << std::endl;
		char c = 'c';
		char d = 'd';
		std::cout << "before swap: c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "after  swap: c = " << c << ", d = " << d << std::endl;
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		std::cout << "--------------------" << std::endl << std::endl;
	}
return 0;
}