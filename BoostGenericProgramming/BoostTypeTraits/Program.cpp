// Program.cpp
//
//Boost.TypeTraits
//Boost.TypeTraits library provides the tools needed to determine a type’s properties and change them.

#include <boost/type_traits.hpp>
#include <iostream>

using namespace boost;

int main()
{
	/*--------------------------------------------------------------------------
	//1. Determining type categories
	std::cout.setf(std::ios::boolalpha);
	std::cout << is_integral<int>::value << std::endl;
	std::cout << is_floating_point<int>::value << std::endl;
	std::cout << is_arithmetic<int>::value << std::endl;
	std::cout << is_reference<int>::value << std::endl;
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//2. boost::true_type and boost::false_type
	std::cout.setf(std::ios::boolalpha);
	std::cout << is_same<is_integral<int>::type, true_type>::value << std::endl;
	std::cout << is_same<is_floating_point<int>::type, false_type>::value << std::endl;
	std::cout << is_same<is_arithmetic<int>::type, true_type>::value << std::endl;
	std::cout << is_same<is_reference<int>::type, false_type>::value << std::endl;
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//3. Checking type properties with Boost.TypeTraits
	std::cout.setf(std::ios::boolalpha);
	std::cout << has_plus<int>::value << std::endl;
	std::cout << has_post_increment<int>::value << std::endl;
	std::cout << has_trivial_copy<int>::value << std::endl;
	std::cout << has_virtual_destructor<int>::value << std::endl;
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------*/
	//4. Changing type properties with Boost.TypeTraits
	std::cout.setf(std::ios::boolalpha);
	std::cout << is_const<add_const<int>::type>::value << std::endl;
	std::cout << is_same<remove_pointer<int*>::type, int>::value << std::endl;
	std::cout << is_same<make_unsigned<int>::type, unsigned int>::value << std::endl;
	std::cout << is_same<add_rvalue_reference<int>::type, int&&>::value << std::endl;
	/*--------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}