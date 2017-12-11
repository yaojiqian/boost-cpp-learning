// Program.cpp
//
//Boost.Integer
#include <boost/cstdint.hpp>
#include <iostream>


int main()
{
	/*-----------------------------------------------------------------
	//1. Types for integers with number of bits
	boost::int8_t i8 = 1;
	std::cout << sizeof(i8) << std::endl;

#ifndef BOOST_NO_INT64_T
	boost::uint64_t ui64 = 1;
	std::cout << sizeof(ui64) << std::endl;
#endif

	boost::int_least8_t il8 = 1;
	std::cout << sizeof(il8) << std::endl;

	boost::int_least32_t il32 = 1;
	std::cout << sizeof(il32) << std::endl;

	boost::int_fast8_t if8 = 1;
	std::cout << sizeof(if8) << std::endl;

	boost::uint_fast16_t uif16 = 1;
	std::cout << sizeof(uif16) << std::endl;

	/*-----------------------------------------------------------------*/

	/*-----------------------------------------------------------------*/
	//2. More specialized types for integers
	boost::intmax_t imax = 1;
	std::cout << sizeof(imax) << std::endl;

	std::cout << sizeof(UINT8_C(1)) << std::endl;

#ifndef BOOST_NO_INT64_T
	/*boost::uint64_t ui64 = 1;
	std::cout << sizeof(ui64) << std::endl;*/
	std::cout << sizeof(UINT64_C(1)) << std::endl;
#endif

	/*-----------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}