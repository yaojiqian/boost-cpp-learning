// Program.cpp
//
//Boost.Fusion
//Boost.Fusion makes it possible to create heterogeneous containers.
//

//#include <boost/fusion/tuple.hpp>
//#include <boost/fusion/algorithm.hpp>
//#include <boost/fusion/iterator.hpp>

#include <boost/fusion/sequence.hpp>
#include <boost/mpl/int.hpp>

//#include <boost/fusion/container.hpp>

#include <boost/fusion/adapted.hpp>

//#include <boost/type_traits.hpp>
//#include <boost/mpl/arg.hpp>
//#include <string>
#include <iostream>


/*------------------------------------------------------------------------
//2. Iterating over a tuple with boost::fusion::for_each()
//3. Filtering a Fusion container with boost::fusion::filter_view
struct print
{
	template<typename T>
	void operator()(const T &t) const
	{
		std::cout << std::boolalpha << t << std::endl;
	}
};
/*------------------------------------------------------------------------*/


/*------------------------------------------------------------------------*/
//7. Fusion adaptors for structures
struct strct
{
	int i;
	double d;
};

BOOST_FUSION_ADAPT_STRUCT(strct, (int, i), (double, d))

/*------------------------------------------------------------------------*/

using namespace boost::fusion;

int main()
{
	/*------------------------------------------------------------------------
	//1. Processing Fusion tuples
	typedef tuple< int, std::string, bool, double > tuple_type;
	tuple_type t{ 10, "Boost", true, 3.14 };
	std::cout << get<0>(t) << std::endl;
	std::cout << get<1>(t) << std::endl;
	std::cout << std::boolalpha << get<2>(t) << std::endl;
	std::cout << get<3>(t) << std::endl;
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//2. Iterating over a tuple with boost::fusion::for_each()
	typedef tuple<int, std::string, bool, double> tuple_type;
	tuple_type t{ 10, "Boost", true, 4.13 };
	for_each(t, print{});
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//3. Filtering a Fusion container with boost::fusion::filter_view
	typedef tuple<int, std::string, bool, double> tuple_type;
	tuple_type t{ 10, "Boost", true, 3.14 };
	filter_view<tuple_type, boost::is_integral<boost::mpl::arg<1>>> v{ t };
	for_each(v, print{});
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//4. Accessing elements in Fusion containers with iterators
	typedef tuple<int, std::string, bool, double> tuple_type;
	tuple_type t{ 10, "Boost",false, 3.14 };
	auto it = begin(t);
	std::cout << *it << std::endl;
	auto it2 = advance<boost::mpl::int_<1>>(it);
	std::cout << std::boolalpha << *it2 << std::endl;
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//5. A heterogeneous vector with boost::fusion::vector
	typedef vector<int, std::string, bool, double> vector_type;
	vector_type v{ 10, "Boost", true, 3.14 };
	std::cout << at<boost::mpl::int_<0>>(v) << std::endl;

	auto v2 = push_back(v, "X");//v2's type is vector<int, std::string, bool, double, std::string>
	std::cout << size(v) << std::endl;
	std::cout << size(v2) << std::endl;
	std::cout << back(v2) << std::endl;
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//6. A heterogeneous map with boost::fusion::map
	auto m = make_map<int, std::string, bool, double>("Boost", 10, 3.14, true);
	if (has_key<std::string>(m))
		std::cout << at_key<std::string>(m) << std::endl;

	std::cout << std::boolalpha << at_key<double>(m) << std::endl;

	auto m2 = erase_key<std::string>(m);
	auto m3 = push_back(m2, make_pair<float>("X"));
	std::cout << std::boolalpha << has_key<std::string>(m3) << std::endl;
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//7. Fusion adaptors for structures
	strct s{ 10,3.14 };
	std::cout << at<boost::mpl::int_<0>>(s) << '\n';
	std::cout << back(s) << '\n';
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------*/
	//8. Fusion support for std::pair
	auto p = std::make_pair(10, 3.14);
	std::cout << at<boost::mpl::int_<1>>(p) << '\n';
	std::cout << back(p) << '\n';
	/*------------------------------------------------------------------------*/

	std::wcout << std::endl << "press a key to exit";
	std::getchar();
	return 0;
}