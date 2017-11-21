// Program.cpp
//
//The library Boost.CircularBuffer provides a circular buffer,
//which is a container with the following two fundamental properties:
//
//	The capacity of the circular buffer is constant and set by you.
//	The capacity doesn’t change automatically when you call a member function such as push_back().
//	Only you can change the capacity of the circular buffer.
//	The size of the circular buffer can not exceed the capacity you set.
//
//	Despite constant capacity, you can call push_back() as often as you 
//	like to insert elements into the circular buffer.
//	If the maximum size has been reached and the circular buffer is full, 
//	elements are overwritten.
//

#include <boost/circular_buffer.hpp>

#include <iostream>


int main()
{
	/*-------------------------------------------------
	// 1. Using boost::circular_buffer
	//
	typedef boost::circular_buffer<int> circular_buffer;
	circular_buffer cb{ 3 };

	std::cout << cb.capacity() << std::endl;
	std::cout << cb.size() << std::endl;

	cb.push_back(1);
	cb.push_back(2);
	cb.push_back(3);

	std::cout << cb.capacity() << std::endl;
	std::cout << cb.size() << std::endl;

	for (const auto &it : cb)
		std::cout << it << std::endl;

	cb.push_back(4);
	cb.push_back(5);
	cb.push_back(6);

	std::cout << cb.capacity() << std::endl;
	std::cout << cb.size() << std::endl;

	for (const auto &it : cb)
		std::cout << it << std::endl;

	-------------------------------------------------*/

	/*-------------------------------------------------*/
	// 2. Various member functions of boost::circular_buffer
	//
	typedef boost::circular_buffer<int> circular_buffer;
	circular_buffer cb{ 3 };

	std::cout << cb.capacity() << std::endl;
	std::cout << cb.size() << std::endl;

	cb.push_back(0);
	cb.push_back(1);
	cb.push_back(2);
	cb.push_back(3);

	std::cout << std::boolalpha<< cb.is_linearized() << std::endl;
	
	circular_buffer::array_range ar1, ar2;

	ar1 = cb.array_one();
	ar2 = cb.array_two();
	std::cout << ar1.second << ";" << ar2.second << std::endl;

	for (int i : cb)
		std::cout << i << std::endl;

	cb.linearize();

	ar1 = cb.array_one();
	ar2 = cb.array_two();

	std::cout << ar1.second << ";" << ar2.second << std::endl;
	/*-------------------------------------------------*/

	std::getchar();
	return 0;
}