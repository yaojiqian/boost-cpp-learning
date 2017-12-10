// Program.cpp
//
//Language Extensions
//Coroutine
//with Boost.Coroutine it is possible to return from functions and continue later from the same location.

#include <boost/coroutine2/all.hpp>
#include <functional>
#include <tuple>
#include <string>
#include <iostream>

#include <stdexcept>

/*--------------------------------------------------------------------------
//1. Using coroutines
//pull_type and push_type. One of these types will be used to create an object 
//that will be initialized with the function you want to use as a coroutine. 
//The other type will be the first parameter of the coroutine function.

using namespace boost::coroutines2;

void cooperative(coroutine<void>::push_type &sink)
//push_type will be the first parameter of the coroutine function.
{
	std::cout << "Hello";
	sink();
	std::cout << "world";
}

/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
//2. Returning a value from a coroutine

using namespace boost::coroutines2;
void cooperative(coroutine<int>::push_type &sink, int i)
{
	int j = i;
	sink(++j);
	sink(++j);
	std::cout << "end\n";
}
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
//3. Passing two values to a coroutine
using boost::coroutines2::coroutine;
void cooperative(coroutine < std::tuple<int, std::string>>::pull_type &source)
{
	auto args = source.get();
	std::cout << std::get<0>(args) << " " << std::get<1>(args) << std::endl;
	source();
	args = source.get();
	std::cout << std::get<0>(args) << " " << std::get<1>(args) << std::endl;
}
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
//4. Coroutines and exceptions

using boost::coroutines2::coroutine;
void cooperative(coroutine<void>::push_type &sink)
{
	sink();
	throw std::runtime_error("error");
}
/*--------------------------------------------------------------------------*/

int main()
{
	/*--------------------------------------------------------------------------
	//1. Using coroutines
	coroutine<void>::pull_type source{ cooperative }; 
	//pull_type will be used to create an object that will be initialized with the function you want to use as a coroutine. 
	std::cout << ", ";
	source();
	std::cout << "!\n";
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//2. Returning a value from a coroutine
	using std::placeholders::_1;
	coroutine<int>::pull_type source{ std::bind(cooperative,_1,0) };
	std::cout << source.get() << std::endl;
	source();
	std::cout << source.get() << std::endl;
	source();
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//3. Passing two values to a coroutine
	coroutine<std::tuple<int, std::string>>::push_type sink{ cooperative };
	sink(std::make_tuple(1, "aaa"));
	sink(std::make_tuple(2, "bbb"));
	std::cout << "end\n";
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------*/
	//4. Coroutines and exceptions
	coroutine<void>::pull_type source{ cooperative };
	try {
		source();
	}
	catch (std::runtime_error &ex) {
		std::cout << ex.what();
	}
	/*--------------------------------------------------------------------------*/


	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}