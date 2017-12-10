// Program.cpp
//
//Boost.Foreach
//

#include <boost/foreach.hpp>
#include <array>
#include <iostream>


int main()
{

	//1. Using BOOST_FOREACH and BOOST_REVERSE_FOREACH
	std::array<int, 5> a{ 0,1,2,3,4 };

	BOOST_FOREACH(int &i, a)
		i *= i;

	BOOST_REVERSE_FOREACH(int i, a)
	{
		std::cout << i << " ";
	}

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}