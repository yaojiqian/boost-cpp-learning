// Program.cpp
//
//Boost.NumericConversion
//
#include <boost/numeric/conversion/cast.hpp>
#include <iostream>


int main()
{
	/*---------------------------------------------------------------
	//1. Implicit conversion from int to short
	int i = 0x10000;
	short s = i;
	std::cout << s << std::endl;
	/*---------------------------------------------------------------*/

	/*---------------------------------------------------------------
	//2. Overflow detection with boost::numeric_cast
	try
	{
		int i = 0x10000;
		short s = boost::numeric_cast<short>(i);
		std::cout << s << std::endl;
	}
	catch (boost::numeric::bad_numeric_cast &e)
	{
		std::cout << e.what() << std::endl;
	}
	/*---------------------------------------------------------------*/

	/*---------------------------------------------------------------*/
	//3. Overflow detection for negative numbers
	try
	{
		int i = -0x10000;
		short s = boost::numeric_cast<short>(i);
		std::cout << s << std::endl;
	}
	catch (boost::numeric::bad_numeric_cast & e)
	{
		std::cout << e.what();
	}
	/*---------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}