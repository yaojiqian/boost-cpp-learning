// Program.cpp
//
//Boost.Uuid
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>

using namespace boost::uuids;

int main()
{
	/*------------------------------------------------------------------------
	//1. Generating random UUIDs with boost::uuids::random_generator
	random_generator gen;
	uuid id = gen();
	std::cout << id << std::endl;
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//2. Member functions of boost::uuids::uuid
	random_generator gen;
	uuid id = gen();

	std::cout << id.size() << std::endl;
	std::cout << std::boolalpha << id.is_nil() << std::endl;
	std::cout << id.variant() << std::endl;
	std::cout << id.version() << std::endl;
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//3. Generators from Boost.Uuid
	nil_generator nil_gen;
	uuid id = nil_gen();
	std::cout << std::boolalpha << id.is_nil() << std::endl;

	string_generator str_gen;
	id = str_gen("96A418B7-519F-4BF5-9D86-BD756149F5BB");
	std::cout << id.variant() << std::endl;

	name_generator name_gen(id);
	std::cout << name_gen("theboostcpplibraries.com") << '\n';
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------*/
	//4. Conversion to strings
	random_generator gen;
	uuid id = gen();

	std::string s = to_string(id);
	std::cout << s << '\n';

	std::cout << boost::lexical_cast<std::string>(id) << '\n';
	/*------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}