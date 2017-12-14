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

/*-----------------------------------------------------------------------------------------
//2. One string instead of a hundred thousand strings with Boost.Flyweight
using namespace boost::flyweights;
struct person
{
	int id_;
	flyweight<std::string> city_;
	person(int id, std::string city) :id_{ id }, city_{ std::move(city) } {}
};

/*-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------
//3. Using boost::flyweights::flyweight multiple times
using namespace boost::flyweights;
struct person
{
	int id_;
	flyweight<std::string> city_;
	flyweight<std::string> country_;
	//std::string city_;
	//std::string country_;
	person(int id, std::string city, std::string country) :id_{ id }, city_{ std::move(city) }, country_{ std::move(country)} {}
};
/*-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------
//4. Using boost::flyweights::flyweight multiple times with tags
using namespace boost::flyweights;

struct city {};
struct country {};

struct person
{
	int id_;

	//The tags make city_ and country_ use different types. 
	//Now two hash containers are used by Boost.Flyweight 
	//– one stores cities, the other stores countries.
	flyweight<std::string, tag<city>> city_;
	flyweight<std::string, tag<country>> country_;
	person(int id, std::string city, std::string country) :id_{ id }, city_{ std::move(city) }, country_{ std::move(country) } {}
};
/*-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------*/
//5. Template parameters of boost::flyweights::flyweight
#include <boost/flyweight/set_factory.hpp>
#include <boost/flyweight/no_locking.hpp>
#include <boost/flyweight/no_tracking.hpp>
#include <boost/flyweight/hashed_factory.hpp>
using namespace boost::flyweights;
struct person
{
	int id_;
	flyweight<std::string, set_factory<>, no_locking, no_tracking> city_;
	//flyweight<std::string, hashed_factory<>, no_locking, no_tracking> city_;
	//boost::flyweights::set_factory tells Boost.Flyweight 
	//to use a sorted container, such as std::set, rather than a hash container.
	//**it's more lower preformace than hash container;**

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

	/*-----------------------------------------------------------------------------------------
	//2. One string instead of a hundred thousand strings with Boost.Flyweight
	std::vector<person> persons;
	for (int i = 0; i < 100000;i++)
	{
		persons.push_back({ i, "Berlin" });
	}
	/*-----------------------------------------------------------------------------------------*/

	/*-----------------------------------------------------------------------------------------
	//3. Using boost::flyweights::flyweight multiple times
	std::vector<person> persons;
	for (int i = 0; i < 100000; i++)
		persons.push_back({ i, "Berlin", "Germany" });
	/*-----------------------------------------------------------------------------------------*/

	/*-----------------------------------------------------------------------------------------
	//4. Using boost::flyweights::flyweight multiple times with tags
	std::vector<person> persons;
	for (int i = 0; i < 100000; i++)
		persons.push_back({ i, "Berlin", "Germany" });
	/*-----------------------------------------------------------------------------------------*/

	/*-----------------------------------------------------------------------------------------*/
	//5. Template parameters of boost::flyweights::flyweight
	std::vector<person> persons;
	for (int i = 0; i < 100000; i++)
		persons.push_back({ i, "Berlin"});
	/*-----------------------------------------------------------------------------------------*/


	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}