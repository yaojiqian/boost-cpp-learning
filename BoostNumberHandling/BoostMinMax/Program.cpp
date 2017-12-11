// Program.cpp
//
//Boost.MinMax
//
#include <boost/algorithm/minmax.hpp>
#include <boost/algorithm/minmax_element.hpp>
#include <boost/tuple/tuple.hpp>
#include <array>
#include <utility>
#include <iostream>


int main()
{
	/*------------------------------------------------------------------
	//1. Using boost::minmax()
	int i = 2;
	int j = 1;
	boost::tuples::tuple<const int&, const int&> t = boost::minmax(i, j);
	std::cout << t.get<0>() << std::endl;
	std::cout << t.get<1>() << std::endl;
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------*/
	//2. Using boost::minmax_element()
	typedef std::array<int, 4> array;
	array a{ { 2, 3, 0, 1 } };

	std::pair<array::iterator, array::iterator> p = boost::minmax_element(a.begin(), a.end());

	std::cout << *p.first << std::endl;
	std::cout << *p.second << std::endl;
	/*------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}