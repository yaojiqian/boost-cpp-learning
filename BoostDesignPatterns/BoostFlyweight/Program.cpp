// Program.cpp
//Boost.Flyweight

#include <boost/flyweight.hpp>
#include <string>
#include <vector>
#include <iostream>

/*-----------------------------------------------------------------------------------------
//1. A hundred thousand identical strings without Boost.Flyweight
struct person
{
	int id_;
	std::string city_;
};
/*-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------*/
//2. One string instead of a hundred thousand strings with Boost.Flyweight
using namespace boost::flyweights;
struct person
{
	int id_;
	flyweight<std::string> city_;
	person(int id, std::string city) :id_{ id }, city_{ std::move(city) } {}
};

/*-----------------------------------------------------------------------------------------*/

int main()
{
	/*-----------------------------------------------------------------------------------------
	//1. A hundred thousand identical strings without Boost.Flyweight
	std::vector<person> persons;
	for (int i = 0; i < 100000; i++)
	{
		persons.push_back({ i, "Berlin" });
	}
	/*-----------------------------------------------------------------------------------------*/

	/*-----------------------------------------------------------------------------------------*/
	//2. One string instead of a hundred thousand strings with Boost.Flyweight
	std::vector<person> persons;
	for (int i = 0; i < 100000;i++)
	{
		persons.push_back({ i, "Berlin" });
	}
	/*-----------------------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}