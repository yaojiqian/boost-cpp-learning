// Program.cpp
//
//Boost Range Algorithms
//
//You can think of a range as two iterators that refer to the beginning and end 
//of a group of elements that you can iterate over. 
//Because all containers support iterators, every container can be thought of as a range. 
//Since all algorithms from Boost.Range expect a range as a first parameter, 
//a container like std::vector can be passed directly. 
//You don’t have to call begin() and end() and then pass two iterators separately. 
//This protects you from mistakes such as passing the begin and end iterator in 
//the wrong order or passing iterators that belong to two different containers.

#include <iostream>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <boost/range/numeric.hpp>
#include <array>
#include <iterator>
#include <vector>
#include <deque>

int main()
{
	/*----------------------------------------------------------
	//1. Counting with boost::count()
	std::array<int, 6> a{ { 0, 1, 0, 1, 0, 4 } };
	//boost::count returns the count of special value in the container.
	std::cout << boost::count(a, 4) << std::endl;
	/*----------------------------------------------------------*/

	/*----------------------------------------------------------
	//2. Range algorithms related to algorithms from the standard library
	std::array<int, 6> a{ { 0, 1, 2, 3,4, 5 } };
	boost::random_shuffle(a);
	boost::copy(a, std::ostream_iterator<int>(std::cout, ","));
	
	std::cout << std::endl << *boost::max_element(a) << std::endl;
	std::cout << boost::accumulate(a, 0) << std::endl;
	/*----------------------------------------------------------*/

	/*----------------------------------------------------------*/
	//3. Range algorithms without counterparts in the standard library
	std::array<int, 6> a{ { 0, 1, 2, 3,4, 5 } };
	std::cout << std::boolalpha << boost::is_sorted(a) << std::endl;
	std::deque<int> d;

	boost::push_back(d, a);
	std::cout << "=======" << std::endl;
	boost::copy(d, std::ostream_iterator<int>(std::cout, ","));
	std::cout << std::endl;
	boost::remove_erase(d, 2);

	boost::copy_n(d, 3, std::ostream_iterator<int>(std::cout, ","));
	/*----------------------------------------------------------*/

	std::getchar();
	return 0;
}