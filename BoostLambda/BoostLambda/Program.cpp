// Program.cpp
//
//Boost.Lambda
//

#include <boost/lambda/lambda.hpp>
#include <boost/lambda/if.hpp>
#include <vector>
#include <algorithm>
#include <iostream>


int main()
{
	/*-------------------------------------------------------
	//1. std::for_each() with a lambda function
	std::vector<int> v{ 1,3,2 };
	std::for_each(v.begin(), v.end(), std::cout << boost::lambda::_1 << "\n");
	/*-------------------------------------------------------*/


	/*-------------------------------------------------------*/
	//2. A lambda function with boost::lambda::if_then()
	std::vector<int> v{ 1,3,2 };
	std::for_each(v.begin(), v.end(), boost::lambda::if_then(boost::lambda::_1 > 1, std::cout << boost::lambda::_1 << "\n"));
	/*-------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}