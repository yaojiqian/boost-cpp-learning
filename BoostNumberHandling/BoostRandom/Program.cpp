// Program.cpp
//
//Boost.Random
//
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>
#include <ctime>
#include <cstdint>
#include <iostream>


int main()
{
	/*----------------------------------------------------------------------------
	//1. Pseudo-random numbers with boost::random::mt19937
	std::time_t now = std::time(0);
	boost::random::mt19937 gen{ static_cast<uint32_t>(now) };
	std::cout << gen() << std::endl;
	/*----------------------------------------------------------------------------*/

	/*----------------------------------------------------------------------------
	//2. Real random numbers with boost::random::random_device
	boost::random_device gen;
	std::cout << gen() << std::endl;
	/*----------------------------------------------------------------------------*/

	/*----------------------------------------------------------------------------
	//3. The random numbers 0 and 1 with bernoulli_distribution
	std::time_t now = std::time(0);
	boost::random::mt19937 gen{ static_cast<uint32_t>(now) };
	boost::random::bernoulli_distribution<> dist;
	std::cout << dist(gen) << std::endl;
	/*----------------------------------------------------------------------------*/

	/*----------------------------------------------------------------------------*/
	//4. Random numbers between 1 and 100 with uniform_int_distribution
	std::time_t now = std::time(0);
	boost::random::mt19937 gen{ static_cast<uint32_t>(now) };
	boost::random::uniform_int_distribution<> dist{ 1,100 };
	std::cout << dist(gen) << std::endl;
	/*----------------------------------------------------------------------------*/


	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}