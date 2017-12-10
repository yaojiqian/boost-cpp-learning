// Program.cpp
//
//Boost.Parameter
//
//Boost.Parameter makes it possible to pass parameters as key/value pairs.

#include <boost/parameter.hpp>
#include <string>
#include <iostream>
#include <ios>


/*--------------------------------------------------------------------------------------
//1. Function parameters as key/value pairs
BOOST_PARAMETER_NAME(a)
BOOST_PARAMETER_NAME(b)
BOOST_PARAMETER_NAME(c)
BOOST_PARAMETER_NAME(d)
BOOST_PARAMETER_NAME(e)

BOOST_PARAMETER_FUNCTION(
	(void),
	complicated,
	tag,
	(required
		(a, (int))
		(b, (char))
		(c, (double))
		(d, (std::string))
		(e, *)
	)
)
{
	std::cout.setf(std::ios::boolalpha);
	std::cout << a << '\n';
	std::cout << b << '\n';
	std::cout << c << '\n';
	std::cout << d << '\n';
	std::cout << e << '\n';
}
/*--------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------*/
//2. Optional function parameters

BOOST_PARAMETER_NAME(a)
BOOST_PARAMETER_NAME(b)
BOOST_PARAMETER_NAME(c)
BOOST_PARAMETER_NAME(d)
BOOST_PARAMETER_NAME(e)

BOOST_PARAMETER_FUNCTION(
	(void),
	complicated,
	tag,
	(required
		(a, (int))
		(b, (char)))
	(optional
		(c, (double), 3.14)
		(d, (std::string), "Boost")
		(e, (*), true))
)
{
	std::cout.setf(std::ios::boolalpha);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
}
/*--------------------------------------------------------------------------------------*/
int main()
{
	/*--------------------------------------------------------------------------------------
	//1. Function parameters as key/value pairs
	complicated(_a = 10, _b = 'k', _e = true, _d = "hello");
	/*--------------------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------------------*/
	//2. Optional function parameters
	complicated(_b = 'c', _a = 12, _d="hello");
	/*--------------------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}