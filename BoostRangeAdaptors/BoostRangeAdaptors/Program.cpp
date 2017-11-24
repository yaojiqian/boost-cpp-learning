// Program.cpp
//
//Boost Range Adaptors
//You can think of adaptors as filters. They return a new range based on another range. 
//Data isn’t necessarily copied. Since a range is just a pair of iterators, 
//an adaptor returns a new pair. The pair can still be used to iterate over the original range but may, 
//for example, skip certain elements. If boost::count() is used with such an adaptor, 
//boost::count_if() is no longer required. Algorithms don’t have to be defined multiple times 
//just so they can be called with and without predicates.
//

#include <iostream>

#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/regex.h>
#include <array>
#include <map>
#include <iterator>
#include <utility>
#include <string>


int main()
{
	/*----------------------------------------------------------------
	//4. Filtering a range with boost::adaptors::filter()
	std::array<int, 6> a{ {0,5,2,1,3,4} };
	boost::copy(boost::adaptors::filter(a, [](int i) {return i > 2; }), 
		std::ostream_iterator<int>{std::cout, ","});
	/*----------------------------------------------------------------*/


	/*----------------------------------------------------------------
	//5. Using keys(), values() and indirect()
	std::array<int, 3> a{ { 0,1,2} };
	std::map<std::string, int*> m;
	m.insert(std::make_pair("a", &a[0]));
	m.insert(std::make_pair("b", &a[1]));
	m.insert(std::make_pair("c", &a[2]));

	boost::copy(boost::adaptors::keys(m), std::ostream_iterator<std::string>{std::cout, ","});
	boost::copy(boost::adaptors::indirect(boost::adaptors::values(m)), std::ostream_iterator<int>{std::cout, ","});
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	//6. boost::adaptors::tokenize() – an adaptor for strings
	std::string s{"The Boost C++ Libraries"};
	boost::regex expr{ "[\\w+]+" };

	boost::copy(boost::adaptors::tokenize(s, expr, 0, boost::regex_constants::match_default),
		std::ostream_iterator<std::string>{std::cout, ","});
	/*----------------------------------------------------------------*/


	std::getchar();
	return 0;
}