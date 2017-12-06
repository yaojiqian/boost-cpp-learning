// Program.cpp
//
//Boost.Bind

#include <boost/bind.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


//void print(int i)
//{
//	std::cout << i << std::endl;
//}

//class print : public std::binary_function<std::ostream*, int, void>
//{
//public:
//	void operator()(std::ostream *os, int i) const
//	{
//		*os << i << std::endl;
//	}
//};

void print(std::ostream* os, int i)
{
	*os << i << std::endl;
}


bool compare(int i, int j)
{
	return i > j;
}

int main()
{
	/*--------------------------------------------------------------
	//1. std::for_each() with a compatible function
	std::vector<int> v{ 1,2,3,4 };

	std::for_each(v.begin(), v.end(), print);
	/*--------------------------------------------------------------*/

	/*--------------------------------------------------------------
	//2. std::for_each() with std::bind1st()
	std::vector<int> v{ 1,3,2 };
	std::for_each(v.begin(), v.end(), std::bind1st(print{}, &std::cout));
	/*--------------------------------------------------------------*/

	/*--------------------------------------------------------------
	//3. std::for_each() with boost::bind()
	std::vector<int> v{ 1,3,2 };
	std::for_each(v.begin(), v.end(), boost::bind(print, &std::cout, _1));//_1 is a placeholder. Boost.Bind defines placeholders from _1 to _9.
	/*--------------------------------------------------------------*/

	/*--------------------------------------------------------------
	//4. std::sort() with boost::bind()
	std::vector<int> v{ 1,3,2 };
	std::sort(v.begin(), v.end(), boost::bind(compare, _1, _2));
	for (int i : v)
		std::cout << i << std::endl;
	/*--------------------------------------------------------------*/

	/*--------------------------------------------------------------*/
	//5. std::sort() with boost::bind() and changed order of placeholders
	std::vector<int> v{ 1,3,2 };
	std::sort(v.begin(), v.end(), boost::bind(compare, _2, _1));
	for (int i : v)
		std::cout << i << std::endl;
	/*--------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}