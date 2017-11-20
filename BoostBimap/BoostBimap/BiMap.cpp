//BiMap.cpp
//To do some exercises about boost.bimap.
//boost.bimap is a container, it's similar to std::map, but supports looking up value from either side.
//That's mean both of the right side and left side can be the key or the value.
//

#include <boost/bimap.hpp> //bimap is defined in boost/bimap.hpp;
#include <boost/bimap/multiset_of.hpp> // defines boost::bimaps::multiset_of;
#include <boost/bimap/unconstrained_set_of.hpp> //difines boost::bimaps::unconstrained_set_of;

#include <string>
#include <iostream>


int main() 
{

	/*
	// 1. Using boost::bimap
	typedef boost::bimap<std::string, int> bimap;
	bimap animals;

	animals.insert({ "cat", 4 });
	animals.insert({ "shark", 0 });
	animals.insert({ "spider", 8 });

	//bimap provides two members: left and right, which can be used to access
	//the two containers of type std::map that are unified in boost::bimap.
	//Here left uses the keys of type std::string to access the container; and
	//right uses the keys of type int.
	std::cout << animals.left.count("cat") << std::endl;
	std::cout << animals.right.count(8) << std::endl;
	//output:
	//1
	//1
	*/

	/*---------------------------------------------------------------------
	// 2. Accessing relations
	typedef boost::bimap<std::string, int> bimap;
	bimap animals;

	animals.insert({ "cat", 4 });
	animals.insert({ "shark", 0 });
	animals.insert({ "spider", 8 });

	//use iterator to access the bimap's elements;
	for (auto it = animals.begin(); it != animals.end(); it++)
		std::cout << it->left << " has " << it->right << " legs" << std::endl;
	//output:
	//cat has 4 legs
	//shark has 0 legs
	//spider has 8 legs
	---------------------------------------------------------------------*/

	/*---------------------------------------------------------------------
	// 3. Using boost::bimap::set_of explicitly
	//
	//Strictly speaking, the two required template parameters specify container types for left and right, 
	//not the types of the elements to store.If no container type is specified, 
	//the container type boost::bimaps::set_of is used by default.This container, 
	//like std::map, only accepts records with unique keys.
	typedef boost::bimap <boost::bimaps::set_of<std::string>, boost::bimaps::set_of<int>> bimap;
	bimap animals;
	//std::pair<bimap::iterator, bool> p;
	// bimap's insert method returns std::pair,
	//whose property 'second' indicates the success of failed.

	animals.insert({ "cat", 4 });
	animals.insert({ "shark", 0 });
	animals.insert({ "spider", 8 });
	//animals.insert({ "cat", 3 });//This will failed, because 'cat' is not unique.

	std::cout << animals.left.count("spider") << std::endl;
	std::cout << animals.right.count(8) << std::endl;
	//output:
	//1
	//1
	---------------------------------------------------------------------*/

	/*---------------------------------------------------------------------
	// 4. Allowing duplicates with boost::bimaps::multiset_of
	//
	typedef boost::bimap<boost::bimaps::multiset_of<std::string>, boost::bimaps::multiset_of<int>> bimap;
	bimap animals;

	animals.insert({ "cat", 4 });
	animals.insert({ "shark", 0 });
	animals.insert({ "dog", 4 });
	//animals.insert({ "cat", 3 });

	std::cout << animals.left.count("dog") << std::endl;
	std::cout << animals.right.count(4) << std::endl;
	//std::cout << animals.left.count("cat") << std::endl;
	//output:
	//1
	//2
	---------------------------------------------------------------------*/

	/*--------------------------------------------------------------------- */
	// 5. Disabling one side with boost::bimaps::unconstrained_set_of
	//
	typedef boost::bimap<std::string, boost::bimaps::unconstrained_set_of<int>> bimap;
	bimap animals;

	animals.insert({ "cat", 4 });
	animals.insert({ "shark", 0 });
	animals.insert({ "spdier", 8 });

	std::cout << animals.left.count("cat") << std::endl;
	//std::cout << animals.right.count(4) << std::endl; //compile error. 
	//output:
	//1
	/*---------------------------------------------------------------------*/


	std::getchar();
	return 0;
}