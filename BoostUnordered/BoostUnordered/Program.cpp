// Program.cpp
//
//Boost.Unordered provides the classes boost::unordered_set,
//boost::unordered_multiset, boost::unordered_map, 
//and boost::unordered_multimap. 

#include <boost/unordered_set.hpp> //defines boost::unordered_set and boost::unordered_multiset
#include <boost/unordered_map.hpp> //defines boost::unordered_map and boost::unordered_multimap

#include <unordered_set> //defines std::unordered_set and std::unordered_multiset
#include <unordered_map> //defines std::unordered_map and std::unordered_multimap


#include <iostream>
#include <string>


struct animal
{
	std::string name;
	int legs;
};


//In addition to defining hash_value(), 
//you need to make sure two objects can be compared using ==. 
//That’s why the operator operator== is overloaded for animal
bool operator==(const animal& lhs, const animal& rhs)
{
	return ((lhs.name == rhs.name) && (lhs.legs == rhs.legs));
}


//elements of type animal are stored in a container of type boost::unordered_set. 
//Because the hash function of boost::unordered_set doesn’t know the class animal, 
//hash values can’t be automatically calculated for elements of this type. 
//That’s why a hash function must be defined – otherwise the example can’t be compiled.
std::size_t hash_value(const animal &a)
{
	std::size_t seed = 0;
	boost::hash_combine(seed, a.name);
	boost::hash_combine(seed, a.legs);

	return seed;
}

int main()
{

	/*---------------------------------------------------------
	// 1. Using boost::unordered_set
	//
	typedef boost::unordered_set<std::string> unordered_set;
	// boost::unordered_set can be replaced with std::unordered_set
	//
	//typedef std::unordered_set<std::string> unordered_set;
	unordered_set set;

	set.emplace("cat");
	set.emplace("shark");
	set.emplace("spider");

	for (const std::string &s : set) // must use const.
		std::cout << s << std::endl;

	std::cout << set.size() << std::endl;
	std::cout << set.max_size() << std::endl;
	//unlike boost::array, the size and max_size of the boost::unordered_set mostly are not equal.
	// in this test:
	//std::unordered_set's max_size is 119304647
	//boost::unordered_set's max_size is 805306456

	std::cout << std::boolalpha << (set.find("cat") != set.end()) << std::endl;
	std::cout << set.count("shark") << std::endl;
	//output:
	//cat
	//shark
	//spider
	//3
	//119304647   //805306456
	//true
	//1
	---------------------------------------------------------*/

	/*---------------------------------------------------------
	// 2. Using boost::unordered_map
	//
	//typedef boost::unordered_map<std::string, int> unordered_map;
	//
	//boost::unordered_set can be replaced with std::unordered_set
	typedef std::unordered_map<std::string, int> unordered_map;
	unordered_map map;

	map.emplace("cat", 4 );
	map.emplace("shark", 0);
	map.emplace("spider", 8);

	for (const auto &p : map)
		std::cout << p.first << ":" << p.second << std::endl;

	std::cout << map.size() << std::endl;
	std::cout << map.max_size() << std::endl;

	std::cout << std::boolalpha << (map.find("cat") != map.end()) << std::endl;
	std::cout << map.count("shark") << std::endl;

	//output:
	//spider:8
	//shark : 0
	//cat : 4
	//3
	//805306456  //max_size()
	//true
	//1
	---------------------------------------------------------*/


	/*---------------------------------------------------------*/
	// 3. User-defined type with Boost.Unordered
	//
	typedef boost::unordered_set<animal> unordered_set;
	//
	//boost::unordered_set can be replaced with std::unordered_set
	//typedef std::unordered_set<animal> unordered_set;
	unordered_set set;

	set.insert({ "cat", 4 });
	set.insert({ "shark", 0 });
	set.insert({ "spider", 8 });

	for (const animal& a : set)
		std::cout << a.name << ":" << a.legs << std::endl;

	/*---------------------------------------------------------*/

	std::getchar();
	return 0;
}