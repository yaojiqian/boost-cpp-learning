// Program.cpp
//
//Boost Algorithms Range Helpers
//
//


#include <iostream>
#include <array>
#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/sub_range.hpp>

#include <boost/range/istream_range.hpp>

int main()
{
	/*--------------------------------------------------------------------
	//7. Creating a range for integers with boost::irange()
	boost::integer_range<int> ir = boost::irange<int>(0, 3);
	boost::copy(ir, std::ostream_iterator<int>{std::cout, ","});

	/*--------------------------------------------------------------------*/

	/*--------------------------------------------------------------------
	//8. Creating a range for an input stream with boost::istream_range()
	boost::iterator_range<std::istream_iterator<int>> ir = boost::istream_range<int>(std::cin);

	boost::copy(ir, std::ostream_iterator<int>{std::cout, ","});
	/*--------------------------------------------------------------------*/

	/*--------------------------------------------------------------------*/
	//9. Creating ranges more easily with boost::sub_range()
	std::array<int, 6> a{ {0,1,2,3,4,5} };
	boost::iterator_range<std::array<int, 6>::iterator> ir = boost::random_shuffle(a);
	boost::copy(ir, std::ostream_iterator<int>{std::cout, ","});
	std::cout << std::endl;
	boost::sub_range<std::array<int, 6>> sr = boost::random_shuffle(ir);
	boost::copy(sr, std::ostream_iterator<int>{std::cout, ","});
	/*--------------------------------------------------------------------*/

	std::getchar();
	return 0;
}