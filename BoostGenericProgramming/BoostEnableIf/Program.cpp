// Program.cpp
//
//Boost.EnableIf
//

#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <string>
#include <iostream>

/*-----------------------------------------------------------------------------
//1. Overloading functions with boost::enable_if on their return value
template<typename T>
typename boost::enable_if<std::is_same<T, int>, T>::type create()
{
	return 1;
}

template<typename T>
typename boost::enable_if<std::is_same<T, std::string>, T>::type create()
{
	return "Hello";
}
/*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*/
//2. Specializing functions for a group of types with boost::enable_if
template <typename T>
void print(typename boost::enable_if<std::is_integral<T>, T>::type i)
{
	std::cout << i << std::endl;
}

template<typename T>
void print(typename boost::enable_if<std::is_floating_point<T>, T>::type f)
{
	std::cout << f << std::endl;
}
/*-----------------------------------------------------------------------------*/

int main()
{
	/*-----------------------------------------------------------------------------
	//1. Overloading functions with boost::enable_if on their return value
	std::cout << create<int>() << std::endl;
	/*-----------------------------------------------------------------------------*/

	/*-----------------------------------------------------------------------------*/
	//2. Specializing functions for a group of types with boost::enable_if
	print<short>(1);
	print<long>(4);
	print<char>('a');
	print<double>(3.14f);
	/*-----------------------------------------------------------------------------*/


	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}