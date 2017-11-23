// Program.cpp
//
//Boost.CompressedPair
//
//Boost.CompressedPair provides boost::compressed_pair, 
//a class that behaves like std::pair. However, 
//if one or both template parameters are empty classes, 
//boost::compressed_pair consumes less memory. 
//boost::compressed_pair uses a technique known as empty base class optimization.

#include <iostream>
#include <utility>
#include <boost/compressed_pair.hpp>

struct empty {};

int main()
{
	//1. Reduced memory requirements with boost::compressed_pair

	std::pair<int, empty> p;

	std::cout << sizeof(p) << std::endl;

	boost::compressed_pair<int, empty> cp;
	std::cout << sizeof(cp) << std::endl;

	//returns 4 for sizeof(cp) and 8 for sizeof(p).

	std::getchar();
	return 0;
}