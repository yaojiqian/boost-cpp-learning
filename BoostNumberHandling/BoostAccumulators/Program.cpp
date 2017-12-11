// Program.cpp
//
//Boost.Accumulators
//
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>
#include <iostream>

using namespace boost::accumulators;

int main()
{
	/*---------------------------------------------------------------------------
	//1. Counting with boost::accumulators::tag::count
	accumulator_set<int, features<tag::count, tag::mean>> acc;

	acc(4);
	acc(-6);
	acc(9);
	std::cout << count(acc) << std::endl;
	//std::cout << median(acc) << std::endl;
	std::cout << mean(acc) << std::endl;
	/*---------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------*/
	//2. Using mean and variance
	accumulator_set<int, features<tag::mean, tag::variance, tag::median>> acc;
	acc(8);
	acc(9);
	acc(10);
	acc(13);
	acc(11);
	acc(12);
	std::cout << mean(acc) << std::endl;
	std::cout << variance(acc) << std::endl;
	std::cout << median(acc) << std::endl;
	/*---------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------
	//3. Calculating the weighted variance
	accumulator_set<int, features<tag::mean, tag::variance>, int> acc;
	acc(8, weight = 1);
	acc(9, weight = 1);
	acc(10, weight = 4);
	acc(11, weight = 1);
	acc(12, weight = 1);
	std::cout << mean(acc) << std::endl;
	std::cout << variance(acc) << std::endl;
	/*---------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}