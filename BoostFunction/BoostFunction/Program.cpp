// Program.cpp
//
//Boost.Function
//Boost.Function provides a class called boost::function to encapsulate function pointers.

#include <boost/function.hpp>
#include <iostream>
#include <cstdlib>
#include <cstring>


struct world
{
	void Hello(std::ostream &os)
	{
		os << "Hello World!" << std::endl;
	}
};

int main()
{
	/*---------------------------------------------------------------------
	//1. Using boost::function
	boost::function<int(const char*)> f = std::atoi;
	std::cout << f("42") << std::endl;

	//use typedef......
	//typedef int (*funtype)(const char*);
	//funtype ff = &std::atoi;
	//std::cout << ff("42") << std::endl;

	f = std::strlen;
	std::cout << f("42") << std::endl;
	/*---------------------------------------------------------------------*/

	/*---------------------------------------------------------------------
	//2. boost::bad_function_call thrown if boost::function is empty
	try
	{
		boost::function<int(const char*)> f = std::atoi;
		f.clear();
		f("");
	}
	catch (boost::bad_function_call &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	/*---------------------------------------------------------------------*/

	/*---------------------------------------------------------------------*/
	//3. Binding a class member function to boost::function
	//When calling such a function, the first parameter passed 
	//indicates the particular object for which the function is called. 
	//Therefore, the first parameter after the open parenthesis 
	//inside the template definition must be a pointer to that particular class. 
	//The remaining parameters denote the signature of the corresponding member function.
	boost::function<void(world*, std::ostream&)> f = &world::Hello;

	world w;
	f(&w, std::ref(std::cout));
	/*---------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}