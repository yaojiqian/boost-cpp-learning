// Program.cpp
//
//Boost.Phoenix
//Boost.Phoenix supports functional programming with function objects: 
//Functions are objects based on classes which overload the operator operator(). 
//That way function objects behave like other objects in C++. 

#include <boost/phoenix/phoenix.hpp>
#include <vector>
#include <algorithm>
#include <iostream>

bool is_odd(int i) { return i % 2 == 1; }

//struct is_odd_impl
//{
//	typedef bool result_type;
//
//	template <typename T>
//	bool operator()(T t) const { return t % 2 == 1; }
//};
//
//boost::phoenix::function<is_odd_impl> is_odd;

//bool is_odd_function(int i) { return i % 2 == 1; }
//
//BOOST_PHOENIX_ADAPT_FUNCTION(bool, is_odd, is_odd_function, 1);


int main()
{
	/*----------------------------------------------------------------------
	//1. Predicates as global function, lambda function, and Phoenix function
	std::vector<int> v{ 1,2,3,4,5,6,7 };

	std::cout << std::count_if(v.begin(), v.end(), is_odd) << std::endl;

	auto lambda = [](int i) {return i % 2 == 1; };
	std::cout << std::count_if(v.begin(), v.end(), lambda) << std::endl;

	using namespace boost::phoenix::placeholders;
	auto phoenix = arg1 % 2 == 1;
	std::cout << std::count_if(v.begin(), v.end(), phoenix) << std::endl;
	/*----------------------------------------------------------------------*/

	/*----------------------------------------------------------------------
	//2. Phoenix function versus lambda function
	std::vector<int> v{ 1,2,3,4,5 };

	auto lambda = [](int i) {return i % 2 == 1; };
	std::cout << std::count_if(v.begin(), v.end(), lambda) << std::endl;

	std::vector<char> v2;
	v2.insert(v2.begin(), v.begin(), v.end());
	//std::cout << std::count_if(v2.begin(), v2.end(), lambda) << std::endl;

	using namespace boost::phoenix::placeholders;
	auto phoenix = arg1 % 2 == 1;//Phoenix function parameters have no types. 
	std::cout << std::count_if(v.begin(), v.end(), phoenix) << std::endl;
	std::cout << std::count_if(v2.begin(), v2.end(), phoenix) << std::endl;
	//phoenix could process the diferent types with single phoenix.
	/*----------------------------------------------------------------------*/

	/*----------------------------------------------------------------------
	//3. Phoenix functions as deferred C++ code
	std::vector<int> v{ 1,2,3,4,5 };

	using namespace boost::phoenix::placeholders;
	auto phoenix = arg1 > 2 && arg1 % 2 == 1;
	std::cout << std::count_if(v.begin(), v.end(), phoenix) << std::endl;
	/*----------------------------------------------------------------------*/

	/*----------------------------------------------------------------------
	//4. Explicit Phoenix types
	std::vector<int> v{ 1,2,3,4,5 };

	using namespace boost::phoenix;
	using namespace boost::phoenix::placeholders;
	auto phoenix = arg1 > val(2) && arg1 % val(2) == val(1);
	std::cout << std::count_if(v.begin(), v.end(), phoenix) << std::endl;
	/*----------------------------------------------------------------------*/

	/*----------------------------------------------------------------------
	//5. boost::phoenix::placeholders::arg1 and boost::phoenix::val()
	using namespace boost::phoenix;
	std::cout << placeholders::arg1(1, 2, 3, 4, 5) << std::endl;

	auto v = val(2);
	std::cout << v() << std::endl;
	/*----------------------------------------------------------------------*/

	/*----------------------------------------------------------------------
	//6. Creating your own Phoenix functions
	std::vector<int> v{ 1,2,3,4,5 };

	using namespace boost::phoenix::placeholders;
	std::cout << std::count_if(v.begin(), v.end(), is_odd(arg1)) << std::endl;
	/*----------------------------------------------------------------------*/

	/*----------------------------------------------------------------------
	//7. Transforming free-standing functions into Phoenix functions
	std::vector<int> v{ 1,2,3,4,5 };

	using namespace boost::phoenix::placeholders;
	std::cout << std::count_if(v.begin(), v.end(), is_odd(arg1)) << std::endl;
	/*----------------------------------------------------------------------*/

	/*----------------------------------------------------------------------
	//8. Phoenix functions with boost::phoenix::bind()
	std::vector<int> v{ 1,2,3,4,5 };

	using namespace boost::phoenix;
	using namespace boost::phoenix::placeholders;
	std::cout << std::count_if(v.begin(), v.end(), bind(is_odd, arg1));
	/*----------------------------------------------------------------------*/


	/*----------------------------------------------------------------------*/
	//9. Arbitrarily complex Phoenix functions
	std::vector<int> v{ 1,2,3,4,5 };

	using namespace boost::phoenix;
	using namespace boost::phoenix::placeholders;
	int count = 0;
	std::for_each(v.begin(), v.end(), if_(arg1 % 2 == 1)[++ref(count)]);
	std::cout << count << std::endl;
	/*----------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}