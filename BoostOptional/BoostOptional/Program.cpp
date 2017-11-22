// Program.cpp
//
//exercise boost::optional
//
//The library Boost.Optional provides the class boost::optional, 
//which can be used for optional return values. 
//These are return values from functions that may not always return a result. 
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include <boost/optional.hpp>

using boost::optional;

////Without boost::optional, it must return a specail number to spicify no suitable result.
//int get_even_random_number()
//{
//	int i = std::rand();
//	return (i % 2 == 0) ? i : -1;
//};

optional<int> get_even_random_number()
{
	int i = std::rand();
	//return (i % 2 == 0 ? i : optional<int>{});
	//return optional<int>(i % 2 == 0, i);
	return boost::make_optional(i % 2 == 0, i);
}

int main()
{
	/*-----------------------------------------------------------------------------
	//1. Special values to denote optional return values
	std::srand(static_cast<unsigned int>(std::time(0)));
	int i = get_even_random_number();
	if (i != -1)
		std::cout << i << "  " << std::sqrt(static_cast<float>(i)) << std::endl;
	/*-----------------------------------------------------------------------------*/

	/*-----------------------------------------------------------------------------*/
	//2. Optional return values with boost::optional
	std::srand(static_cast<unsigned int>(std::time(0)));
	optional<int> i = get_even_random_number();
	if (i.is_initialized())
		std::cout << i.get() << " " << std::sqrt(static_cast<float>(i.get())) << std::endl;
	/*-----------------------------------------------------------------------------*/

	std::getchar();
	return 0;
}