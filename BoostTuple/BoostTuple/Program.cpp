// Program.cpp
//
//exercise boost::tuple
//
//The library Boost.Tuple provides a class called boost::tuple, 
//which is a generalized version of std::pair. While std::pair can only store exactly two values, 
//boost::tuple lets you choose how many values to store.
//


#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>	//To use tuples with streams
#include <boost/ref.hpp>
#include <boost/tuple/tuple_comparison.hpp>

#include <iostream>
#include <string>


boost::tuple<std::string, int> new_cat()
{
	return boost::make_tuple("cat", 4);
}

int main()
{
	/*-----------------------------------------------------------
	//1. boost::tuple replacing std::pair
	typedef boost::tuple<std::string, int> animal;
	animal a{ "cat",4 };

	std::cout << a << std::endl;
	/*-----------------------------------------------------------*/

	/*-----------------------------------------------------------
	//2. boost::tuple as the better std::pair
	typedef boost::tuple<std::string, int, bool> animal;

	animal a{ "cat", 4, false };
	std::cout << std::boolalpha << a << std::endl;
	/*-----------------------------------------------------------*/

	/*-----------------------------------------------------------
	//3. Creating tuples with boost::make_tuple()
	
	std::cout.setf(std::ios::boolalpha);
	std::cout << boost::make_tuple("cat", 4, true) << std::endl;
	/*-----------------------------------------------------------*/

	/*-----------------------------------------------------------
	//4. Tuples with references
	std::string s{ "cat" };

	std::cout.setf(std::ios::boolalpha);
	std::cout << boost::make_tuple(boost::ref(s), 4, true) << std::endl;
	/*-----------------------------------------------------------*/

	/*-----------------------------------------------------------
	//5. Reading elements of a tuple
	typedef boost::tuple<std::string, int, bool> animal;

	animal a = boost::make_tuple("cat", 4, true);

	std::cout << a.get<0>() << std::endl;
	std::cout << boost::get<1>(a) << std::endl;
	//The member function get() and the free-standing function boost::get() 
	//both return a reference that allows you to change a value inside a tuple.
	/*-----------------------------------------------------------*/

	/*-----------------------------------------------------------
	//6. Writing elements of a tuple
	typedef boost::tuple<std::string, int, bool> animal;

	animal a = boost::make_tuple("cat", 4, true);

	a.get<0>() = "dog";

	std::cout << a.get<0>() << std::endl;
	std::cout << boost::get<1>(a) << std::endl;
	/*-----------------------------------------------------------*/

	/*-----------------------------------------------------------
	//7. Comparing tuples
	typedef boost::tuple<std::string, int, bool> animal;

	animal a1 = boost::make_tuple("cat", 4, true);
	animal a2 = boost::make_tuple("shark", 0, true);

	std::cout << std::boolalpha << (a1 != a2) << std::endl;
	/*-----------------------------------------------------------*/

	/*-----------------------------------------------------------
	//8. Creating a tier with boost::tie()
	typedef boost::tuple<std::string&, int&, bool&> animal;

	std::string name = "cat";
	int legs = 4;
	bool tail = true;

	animal a1 = boost::tie(boost::ref(name), boost::ref(legs), boost::ref(tail));
	name = "dog";
	std::cout << std::boolalpha << a1 << std::endl;
	/*-----------------------------------------------------------*/

	/*-----------------------------------------------------------
	//9. Creating a tier without boost::tie()
	typedef boost::tuple<std::string&, int&, bool&> animal;

	std::string name = "cat";
	int legs = 4;
	bool tail = true;

	animal a1 = boost::make_tuple(boost::ref(name), boost::ref(legs), boost::ref(tail));
	name = "dog";
	std::cout << std::boolalpha << a1 << std::endl;
	/*-----------------------------------------------------------*/

	/*-----------------------------------------------------------*/
	//10. Unpacking return values of a function from a tuple
	std::string name;
	int legs;

	boost::tie(name, legs) = new_cat();

	std::cout << name << " " << legs << std::endl;
	/*-----------------------------------------------------------*/


	std::getchar();
	return 0;
}