// Program.cpp
//
//Exercise for boost::intrusive
//

#include <iostream>
#include <string>
#include <utility>

//#include <boost/intrusive/list.hpp>
#include <boost/intrusive/set.hpp>

using namespace boost::intrusive;


//To store objects of type animal in an intrusive list, 
//the class must provide the variables required by the intrusive list to concatenate elements. 
//Boost.Intrusive provides hooks – classes from which the required variables are inherited. 
//To allow objects of the type animal to be stored in an intrusive list, 
//animal must be derived from the class boost::intrusive::list_base_hook.
//
//exercises 1,2,3
//
//struct animal : public list_base_hook<>
//{
//	std::string name;
//	int legs;
//	animal(std::string s, int l) : name{ std::move(s) }, legs{ l } {}
//};

//---------------------------------------------------------------------------
//exercise 4
//
//Hooks support a parameter to set a link mode. 
//The link mode is set with the class template boost::intrusive::link_mode. 
//If boost::intrusive::auto_unlink is passed as a template parameter, 
//the auto unlink mode is selected.
//
//typedef link_mode<auto_unlink> mode;
//struct animal : public list_base_hook<mode>
//{
//	std::string name;
//	int legs;
//	animal(std::string s, int l) :name{ std::move(s) }, legs{ l } {}
//};

//---------------------------------------------------------------------------
//exercise 4
//
//Hooks support a parameter to set a link mode. 
//The link mode is set with the class template boost::intrusive::link_mode. 
//If boost::intrusive::auto_unlink is passed as a template parameter, 
//the auto unlink mode is selected.
//
struct animal
{
	std::string name;
	int legs;
	set_member_hook<> set_hook;
	animal(std::string s, int l) :name{ std::move(s) }, legs{ l } {}
	bool operator<(const animal& a) const { return legs < a.legs; }
};

int main()
{
	/*--------------------------------------------------------
	//1. Using boost::intrusive::list
	//
	animal a1{ "cat", 4 };
	animal a2{ "shark",0 };
	animal a3{ "spider", 8 };

	typedef list<animal> animal_list;
	animal_list animals;

	animals.push_back(a1);
	animals.push_back(a2);
	animals.push_back(a3);

	a1.name = "dog";
	//the elements which are in the boost::intrusive::list can be accessed from the variable which is added to list. 

	for (const animal& a : animals)
		std::cout << a.name << ":" << a.legs << std::endl;
	//output:
	//dog:4
	//shark:0
	//spider:8
	--------------------------------------------------------*/

	/*--------------------------------------------------------
	//2. Removing and destroying dynamically allocated objects
	//
	animal a1{ "cat", 4 };
	animal a2{ "shark",0 };
	animal *a3 = new animal{ "spider", 8 };

	typedef list<animal> animal_list;
	animal_list animals;

	animals.push_back(a1);
	animals.push_back(a2);
	animals.push_back(*a3);

	for (const animal &a : animals)
		std::cout << a.name << std::endl;
	//output:
	//cat
	//shark
	//spider

	std::cout << "==========================" << std::endl;

	//must remove it from the list. 
	//Make sure that you remove the object from the list before you destroy it – the order is important
	animals.pop_back();
	delete a3;
	for (const animal &a : animals)
		std::cout << a.name << std::endl;
	//output:
	//cat
	//shark
	/*--------------------------------------------------------*/

	/*--------------------------------------------------------
	//3. Removing and destroying with pop_back_and_dispose()
	//
	animal a1{ "cat", 4 };
	animal a2{ "shark",0 };
	animal *a3 = new animal{ "spider", 8 };

	typedef list<animal> animal_list;
	animal_list animals;

	animals.push_back(a1);
	animals.push_back(a2);
	animals.push_back(*a3);

	for (const animal &a : animals)
		std::cout << a.name << std::endl;
	//output:
	//cat
	//shark
	//spider

	std::cout << "==========================" << std::endl;

	//you need to pass to pop_back_and_dispose() a function or function object that does know how to destroy the element.
	animals.pop_back_and_dispose([](animal *a) {delete a; });

	for (const animal &a : animals)
		std::cout << a.name << std::endl;
	//output:
	//cat
	//shark
	/*--------------------------------------------------------*/

	/*--------------------------------------------------------
	//4. Removing and destroying with auto unlink mode
	//
	animal a1{ "cat", 4 };
	animal a2{ "shark",0 };
	animal *a3 = new animal{ "spider", 8 };

	//The auto unlink mode can only be used if the member function size(), 
	//which is provided by all intrusive containers, has no constant complexity.
	typedef constant_time_size<false> constant_time_size_false;
	typedef list<animal, constant_time_size_false> animal_list;
	animal_list animals;

	animals.push_back(a1);
	animals.push_back(a2);
	animals.push_back(*a3);

	for (const animal &a : animals)
		std::cout << a.name << std::endl;
	//output:
	//cat
	//shark
	//spider

	std::cout << "==========================" << animals.size() << std::endl;

	//Just delete a3, and it will be remove from the list.
	//because of auto_unlink, specified in the list_base_hook
	delete a3;

	for (const animal &a : animals)
		std::cout << a.name << std::endl;
	std::cout << animals.size();
	//output:
	//cat
	//shark
	/*--------------------------------------------------------*/

	/*--------------------------------------------------------*/
	//5. Defining a hook for boost::intrusive::set as a member variable
	//
	animal a1{ "cat", 4 };
	animal a2{ "shark",0 };
	animal a3{ "spider", 8 };

	//uses the class boost::intrusive::set_member_hook to define a member variable.
	typedef member_hook<animal, set_member_hook<>, &animal::set_hook> hook;
	typedef set<animal, hook> animal_set;
	animal_set animals;

	animals.push_back(a1);
	animals.push_back(a2);
	animals.push_back(a3);

	for (const animal &a : animals)
		std::cout << a.name << std::endl;
	//output:
	//cat
	//shark
	//spider
	/*--------------------------------------------------------*/

	std::getchar();
	return 0;
}