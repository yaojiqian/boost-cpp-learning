// Program.cpp
//
//Boost.Any provides the class boost::any which, like JavaScript variables, can store arbitrary types of information
//

#include <iostream>

#include <boost/any.hpp>

int main()
{
	/*------------------------------------------------------------------------------
	//1. Using boost::any
	boost::any a = 1;
	a = 3.14;
	a = true;
	/*------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------
	// 2. Storing a string in boost::any
	boost::any s = std::string{ "Boost" };
	/*------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------
	// 3. Accessing values with boost::any_cast
	boost::any a = 1;
	std::cout << boost::any_cast<int>(a) << std::endl;
	a = 3.14;
	std::cout << boost::any_cast<double>(a) << std::endl;
	a = true;
	std::cout << std::boolalpha << boost::any_cast<bool>(a) << std::endl;
	/*------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------
	//4. boost::bad_any_cast in case of an error
	try
	{
		boost::any a = 1;
		std::cout << boost::any_cast<float>(a) << std::endl;
	}
	catch (boost::bad_any_cast& e)
	{
		std::cerr << e.what() << std::endl;
	}
	/*------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------
	//5. Checking type of currently stored value
	boost::any a = 3.14;
	if (!a.empty())
	{
		const std::type_info &ti = a.type();
		std::cout << ti.name() << std::endl;
	}
	/*------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------*/
	//6. Accessing values through a pointer
	boost::any a = 1;
	
	int *p = boost::any_cast<int>(&a);
	std::cout << *p << std::endl;
	/*------------------------------------------------------------------------------*/


	std::getchar();
	return 0;
}