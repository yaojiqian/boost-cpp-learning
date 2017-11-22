// Program.cpp
//
//Exercise boost::container
//

//Boost.Container is a Boost library that provides the same containers as the standard library. 
//Boost.Container focuses on additional flexibility. 
//For example, all containers from this library can be used with Boost.Interprocess in shared memory
//– something that is not always possible with containers from the standard library.
//
//Boost.Container provides additional advantages :
//
//The interfaces of the containers resemble those of the containers in the C++11 standard library.
//For example, they provide member functions such as emplace_back(), 
//which you can use in a C++98 program even though it wasn’t added to the standard library until C++11.
//
//With boost::container::slist or boost::container::stable_vector, Boost.Container offers containers the standard library doesn’t provide.
//
//The implementation is platform independent.The containers behave the same everywhere.
//You don’t need to worry about possible differences between implementations of the standard library.
//
//The containers from Boost.Container support incomplete types and can be used to define recursive containers.

#include <iostream>

#include <boost/container/vector.hpp> //defines boost::container::vector 
#include <boost/container/stable_vector.hpp>

using namespace boost::container;

struct animal
{
	animal() {}
	vector<animal> children;
};

int main()
{
	/*------------------------------------------------------
	//1. Recursive containers with Boost.Container
	animal parent, child1, child2;

	parent.children.push_back(child1);
	parent.children.push_back(child2);
	/*------------------------------------------------------*/

	/*------------------------------------------------------*/
	//2. Using boost::container::stable_vector
	stable_vector<int> v( 2,1 );

	int &i = v[1];
	v.erase(v.begin());
	std::cout << i << std::endl;

	/*------------------------------------------------------*/

	std::getchar();
	return 0;
}