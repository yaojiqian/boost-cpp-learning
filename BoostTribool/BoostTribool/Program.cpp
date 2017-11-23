// Program.cpp
//
//Boost.Tribool
//The library Boost.Tribool provides the class boost::logic::tribool, 
//which is similar to bool. However, while bool can distinguish two states, 
//boost::logic::tribool handles three.

#include <iostream>
#include <boost/logic/tribool.hpp>
#include <boost/logic/tribool_io.hpp>

using namespace boost::logic;
int main()
{

	/*-----------------------------------------------------------------------
	//1. Three states of boost::logic::tribool
	tribool tb;
	std::cout << std::boolalpha << tb << std::endl;

	tb = true;
	tb = false;
	tb = indeterminate;
	if (tb)
		;
	else if (!tb)
		;
	else
		std::cout << "indeterminate\n";
	/*-----------------------------------------------------------------------*/

	/*-----------------------------------------------------------------------*/
	//2. Logical operators with boost::logic::tribool
	std::cout.setf(std::ios::boolalpha);

	tribool b1 = true;
	std::cout << (b1 || indeterminate) << '\n';
	std::cout << (b1 && indeterminate) << '\n';

	tribool b2 = false;
	std::cout << (b2 || indeterminate) << '\n';
	std::cout << (b2 && indeterminate) << '\n';

	tribool b3 = indeterminate;
	std::cout << (b3 || b3) << '\n';
	std::cout << (b3 && b3) << '\n';
	/*-----------------------------------------------------------------------*/

	std::getchar();
	return 0;
}