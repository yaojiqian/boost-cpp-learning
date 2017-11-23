// Program.cpp
//
//Boost.DynamicBitset
//
//The library Boost.DynamicBitset provides the class boost::dynamic_bitset, 
//which is used like std::bitset. 
//The difference is that the number of bits for std::bitset must be specified at compile time, 
//whereas the number of bits for boost::dynamic_bitset is specified at run time.

#include <iostream>
#include <boost/dynamic_bitset.hpp>


int main()
{
	//1. Using boost::dynamic_bitset
	boost::dynamic_bitset<> db{ 3,4 };

	db.push_back(true);
	std::cout << db << std::endl;

	std::cout.setf(std::ios::boolalpha);
	std::cout << db.size() << '\n';
	std::cout << db.count()/*the number of bits and the number of bits currently set*/ << '\n';
	std::cout << db.any() << '\n';
	std::cout << db.none() << '\n';

	std::cout << db[0].flip() << '\n';
	std::cout << ~db[3] << '\n';
	std::cout << db << '\n';

	std::getchar();
	return 0;
}